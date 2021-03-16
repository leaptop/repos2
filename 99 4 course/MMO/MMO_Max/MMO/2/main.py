import numpy as np
import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn import metrics
from sklearn.impute import SimpleImputer

dataset = pd.read_csv('heart_data.csv')
dataset.head()
X = dataset.loc[:, 'age':'thal']
y = dataset['goal']
X = X.replace('?', np.nan)
y = y.replace('?', np.nan)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)
imputer = SimpleImputer()
X_train = imputer.fit_transform(X_train)
clf = DecisionTreeClassifier(max_depth=None , min_samples_leaf=1)
clf.fit(X_train, y_train)
X_test = imputer.transform(X_test)
y_pred = clf.predict(X_test)
print(clf.score(X_train, y_train))
print(clf.score(X_test, y_test))
print(y_pred)


print(clf.max_depth)
print(clf.min_samples_leaf)




