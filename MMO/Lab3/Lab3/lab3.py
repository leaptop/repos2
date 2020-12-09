import math
import random
import numpy as np
import sklearn.linear_model

def load_data(filename):
    with open(filename, 'rb') as file:
        n_channels = np.fromfile(file, dtype=np.int32, count=1)[0]
        n_samples = np.fromfile(file, dtype=np.int32, count=1)[0]
        n_modes = np.fromfile(file, dtype=np.int32, count=1)[0]
        flags = np.fromfile(file, dtype=np.int32, count=1)[0]
        data = np.fromfile(file, dtype=np.complex)
        data = data.reshape((n_channels * n_modes, n_samples), order='F')
        data = data[2]
        return data

def normalize(data, minimum):
    length = data.shape[0]
    for i in range(0, length):
        data[i] /= minimum

def find_min(data):
    m = 9999999
    for d in data:
        m = min(m, abs(np.real(d)), abs(np.imag(d)))
    return m

def qam_value(q, i):
    result = 0
    if i < -2:
        result = 0
    elif i < 0:
        result = 4
    elif i < 2:
        result = 12
    else:
        result = 8

    if q < -2:
        result += 2
    elif q < 0:
        result += 3
    elif q < 2:
        result += 1
    
    return result

def count_set_bits(n): 
    count = 0
    while (n): 
        count += n & 1
        n >>= 1
    return count 

def get_original_errors_percentage(rx, tx):
    length = rx.shape[0]
    n_errors = 0
    for i in range(length):
        r_value = qam_value(np.real(rx[i]), np.imag(rx[i]))
        t_value = qam_value(np.real(tx[i]), np.imag(tx[i]))
        n_errors += count_set_bits(r_value ^ t_value)
        # if r_value != t_value:
        #     n_errors += 1
    return n_errors / (length*4)

def create_regression(rx_real, rx_imag, tx_real, tx_imag, one_side_neighbours):
    x = construct_xs(rx_real, rx_imag, one_side_neighbours)
    y = construct_ys(tx_real, tx_imag, one_side_neighbours)

    regression = sklearn.linear_model.LinearRegression()
    regression.fit(x, y)

    return regression

def construct_xs(rx_real, rx_imag, one_side_neighbours):
    neigh = one_side_neighbours
    x_num = 2 * (rx_real.shape[0] - 2 * neigh)
    x = np.empty((x_num, 2 * (1 + 2 * neigh)))
    j = 0
    for i in range(neigh, neigh + int(x_num / 2)):
        reals = rx_real[i - neigh : i + neigh + 1]
        imags = rx_imag[i - neigh : i + neigh + 1]
        x[j] = np.concatenate((reals, np.negative(imags)), axis=0)
        j += 1
        x[j] = np.concatenate((imags, reals), axis=0)
        j += 1
    return x

def construct_ys(tx_real, tx_imag, one_side_neighbours):
    neigh = one_side_neighbours
    length = tx_real.shape[0]
    y_real = tx_real[neigh : length - neigh]
    y_imag = tx_imag[neigh : length - neigh]
    # interleaving the Re and Im parts: y_real[0], y_imag[0], y_real[1], ...
    y = np.ravel(np.column_stack((y_real, y_imag)))
    return y

def calc_errors_percentage(rx_train, rx_test, tx_train, tx_test, one_side_neighbours):
    regression = create_regression(
        np.real(rx_train), np.imag(rx_train), 
        np.real(tx_train), np.imag(tx_train), 
        one_side_neighbours
    )

    def errors_percentage(rx, tx, neigh):
        x = construct_xs(np.real(rx), np.imag(rx), neigh)
        y = construct_ys(np.real(tx), np.imag(tx), neigh)
        predicted_y = regression.predict(x)
        # for i in range(10):
        #     print("XXX ", y[i], x[i], predicted_y[i])
        # exit(0)
        length = int(x.shape[0] / 2)
        errors = 0
        for i in range(length):
            test_value = qam_value(y[i * 2], y[i * 2 + 1])
            predicted_value = qam_value(predicted_y[i * 2], predicted_y[i * 2 + 1])
            errors += count_set_bits(test_value ^ predicted_value)
            # if test_value != predicted_value:
            #     errors += 1
        return errors / (length * 4)

    train_err = errors_percentage(rx_train, tx_train, one_side_neighbours)
    test_err = errors_percentage(rx_test, tx_test, one_side_neighbours)

    return train_err, test_err

def split_data(data, ratio):
    length = data.shape[0]
    n_train = int(length * ratio)
    return data[:n_train], data[n_train:]

def unison_shuffled_copies(a, b):
    assert len(a) == len(b)
    p = np.random.permutation(len(a))
    return a[p], b[p]


rx = load_data('rx.bin')
tx = load_data('tx.bin')
minimum = find_min(tx)
normalize(rx, minimum)
normalize(tx, minimum)

original_error = get_original_errors_percentage(rx, tx)
print("Original: ", original_error)

min_error = original_error
min_error_neighbours = 0
min_error_ratio = 0

ratios = np.arange(0.1, 0.7, 0.1)
for ratio in ratios:
    rx, tx = unison_shuffled_copies(rx, tx)
    rx_train, rx_test = split_data(rx, ratio)
    tx_train, tx_test = split_data(tx, ratio)

    print("Ratio:", ratio)
    for neigh in range(1, 10):
        train_err, test_err = calc_errors_percentage(rx_train, rx_test, tx_train, tx_test, neigh)
        if test_err < min_error:
            min_error = test_err
            min_error_neighbours = neigh
            min_error_ratio = ratio
        print("\tNeighbours:", neigh, "Train errors:", train_err, "Test errors: ", test_err)

print("Min error", min_error, "- with", min_error_neighbours, 
    "neighbours and ", min_error_ratio*100, "% train data")
print("Better than original by", (original_error - min_error) / (original_error * 100), "%")
