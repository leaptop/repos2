from random import randint
import pandas as pd
from sklearn.linear_model import LassoCV
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import normalize

def main() -> int:

    size_white = 0
data = pd.read_csv('winequalityN.csv', header=0).fillna(0).values
for i in data:
    if i[0] == 'white':
    i[0] = 0
size_white += 1
else:
i[0] = 1
x = data[..., 0:12]
y = data[..., 12]
for i in range(len(x[0])):
    x[..., i] = normalize([x[..., i]])
runs = 10
print("\033[32m")
print(f'Общие данные не зависимо от цвета вина:')
result = 0
for _ in range(runs):
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state = randint(0, 10000))
model = LassoCV()
model.fit(x_train, y_train)
prediction = model.predict(x_test)
success = 0
for i in range(len(x_test)):
    if abs(y_test[i] - prediction[i]) < 1:
    success += 1
print(f'Точность: {success / len(x_test) * 100:.4}%')
result += success / len(x_test) * 100
print(f'Среднее значение качества регрессии для {runs} запусков: {result / runs:.
4} % \n
')
x_1 = data[0:size_white, 0:12]
y_1 = data[0:size_white, 12]
for i in range(len(x_1[0])):
    x_1[..., i] = normalize([x_1[..., i]])
print("\033[0m")
print("\033[33m")
print(f'Для белого вина:')
result = 0
for _ in range(runs):
    x_train, x_test, y_train, y_test = train_test_split(x_1, y_1, test_size=0.3, ra
ndom_state = randint(0, 10000))
model = LassoCV()
model.fit(x_train, y_train)
prediction = model.predict(x_test)
success = 0
for i in range(len(x_test)):
    if abs(y_test[i] - prediction[i]) < 1:
    success += 1
print(f'Точность: {success / len(x_test) * 100:.4}%')
result += success / len(x_test) * 100
print(f'Среднее значение качества регрессии для {runs} запусков: {result / runs:.
4} % \n
')
x_2 = data[size_white:, 0:12]
y_2 = data[size_white:, 12]
for i in range(len(x_2[0])):
    x_2[..., i] = normalize([x_2[..., i]])
print("\033[0m")
print("\033[31m")
print(f'Для красного вина:');
result = 0
for _ in range(runs):
    x_train, x_test, y_train, y_test = train_test_split(x_2, y_2, test_size=0.3, ra
ndom_state = randint(0, 10000))
model = LassoCV()
model.fit(x_train, y_train)
prediction = model.predict(x_test)
success = 0
for i in range(len(x_test)):
    if abs(y_test[i] - prediction[i]) < 1:
    success += 1
print(f'Точность: {success / len(x_test) * 100:.4}%')
result += success / len(x_test) * 100
print(f'Среднее значение качества регрессии для {runs} запусков: {result / runs:.
4} % \n
')
print("\033[0m")
if __name__ == '__main__':
    exit(main())
