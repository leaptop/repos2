import csv
import math
import random
from collections import defaultdict
from collections import Counter
from typing import *

import numpy as np
from sklearn import tree
from sklearn.impute import SimpleImputer


class DataItem:
    def __init__(self, row: list):
        self.attributes = [None] * 13
        for i in range(len(self.attributes)):
            self.attributes[i] = None if row[i] == "?" else row[i]
        self.clazz = row[len(row) - 1]

    def __str__(self):
        return str(self.attributes) + ", " + str(self.clazz)

class DecisionTree:
    def __init__(self, train_data: List[DataItem]):
        train_data = [random.choice(train_data) for i in range(len(train_data))]

        n_attributes = len(train_data[0].attributes)
        m = int(math.sqrt(n_attributes))

        self.attr_subset_indexes = random.sample(range(n_attributes), m)
        attribute_subset = [subset_by_indexes(item.attributes, self.attr_subset_indexes) for item in train_data]

        classes = [item.clazz for item in train_data]

        self.sk_dec_tree = tree.DecisionTreeClassifier()
        self.sk_dec_tree.fit(attribute_subset, classes)

    def predict(self, X) -> list:
        X = [subset_by_indexes(attrs, self.attr_subset_indexes) for attrs in X]
        return self.sk_dec_tree.predict(X)

class Forest:
    def __init__(self, trees: List[DecisionTree]):
        self.trees = trees

    def predict(self, X) -> list:
        vote_table = zip(*[dec_tree.predict(X) for dec_tree in self.trees])
        return [one_most_common(votes) for votes in vote_table]

def one_most_common(l):
        return Counter(l).most_common(1)[0][0]

def subset_by_indexes(l: list, indexes: List[int]) -> list:
    return [l[i] for i in indexes]

def read_csv(file: str) -> List[DataItem]:
    with (open(file)) as csv_file:
        reader = csv.reader(csv_file)
        next(reader)  # skip header
        return [DataItem(row) for row in reader]


def group_by_class(data: List[DataItem]) -> dict:
    result = defaultdict(list)
    for entry in data:
        result[entry.clazz].append(entry)
    return result


def split_data(data: List[DataItem], train_data_ratio: float) -> Tuple[List[DataItem], List[DataItem]]:
    if train_data_ratio <= 0:
        return [], data
    if train_data_ratio >= 1:
        return data, []

    n = len(data)
    n_training = int(n * train_data_ratio)

    grouped_by_class = group_by_class(data)
    classes = list(grouped_by_class.keys())

    train_data = []
    test_data = []

    class_i = 0
    for i in range(n):
        class_i = (class_i + 1) % len(classes)
        clazz = classes[class_i]
        group = grouped_by_class[clazz]
        if len(group) == 0:
            classes.remove(clazz)
            continue

        group.pop
        item = group.pop(random.randint(0, len(group) - 1))
        target_data = train_data if i < n_training else test_data
        target_data.append(item)

    return train_data, test_data


def fill_missing_values(data: List[DataItem]) -> List[DataItem]:
    imp = SimpleImputer(missing_values=np.nan, strategy='mean')
    imp = SimpleImputer(missing_values=np.nan, strategy='mean')
    attributes = [item.attributes for item in data]
    imp = imp.fit(attributes)
    attributes_imp = imp.transform(attributes)
    return [DataItem([*attributes_imp[i], data[i].clazz]) for i in range(len(data))]


def count_matches(forest: Forest, test_data: List[DataItem]) -> float:
    matches = 0
    predicted: list = forest.predict([item.attributes for item in test_data])
    for i in range(len(predicted)):
        if predicted[i] == test_data[i].clazz:
            matches += 1
    return matches / len(test_data)


def main():
    all_data = read_csv('data.csv')
    all_data = fill_missing_values(all_data)

    (train_data, test_data) = split_data(all_data, 0.7)

    trees = [DecisionTree(train_data) for i in range(15)]
    forest = Forest(trees)
    
    train_matches = '{:.4f}'.format(count_matches(forest, train_data))
    test_matches = '{:.4f}'.format(count_matches(forest, test_data))
    print("Train: " + str(train_matches))
    print("Test: " + str(test_matches))


if __name__ == '__main__':
    main()
    exit()
