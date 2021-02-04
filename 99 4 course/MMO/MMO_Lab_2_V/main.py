import pandas as pd
import pydotplus
from sklearn import tree
from sklearn.model_selection import train_test_split

import os
os.environ["PATH"] += os.pathsep + 'C:/Program Files/Graphviz 2.44.1/bin/'

df = pd.read_csv('data.csv', header=0)
df = df.replace('?', 0.)
dt = tree.DecisionTreeClassifier(min_samples_leaf=5, max_depth=10)
x = df.values[:, 0:13]
print(x)
print()
y = df.values[:, 13]
y = y.astype('int')
for i in range(10):
    train_x, test_x, train_y, test_y = train_test_split(x, y, test_size=0.3)
dt.fit(train_x, train_y)
print(str(i) + '.На обучающей выборке: ', dt.score(train_x, train_y))
print(str(i) + '.На тестовой выборке: ', dt.score(test_x, test_y))
print()
gv_str = tree.export_graphviz(dt, out_file=None, feature_names=df.head()
                                                               [0:0].columns[:-1])
graph = pydotplus.graph_from_dot_data(gv_str)
graph.write_png("tree.png")
