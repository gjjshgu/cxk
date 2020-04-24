from math import sqrt
import numpy as np
from collections import Counter

class KNNclassifier:
    def __init__(self,k):
        assert k>=1
        self.k=k
        self._x_train = None
        self._y_train = None
    def fit(self,x_train,y_train):
        """
        训练数据
        :param x_train: 特征集
        :param y_train: 结果集
        :return:
        """
        assert x_train.shape[0]==y_train.shape[0]
        assert self.k<=y_train.shape[0]
        self._x_train=x_train
        self._y_train=y_train
        return self
    def _predict(self,x_predict): #单数据
        assert self._x_train is not None
        assert self._y_train is not None
        assert x_predict.shape[0]==self._x_train.shape[1]
        distances=[]
        for x in self._x_train:
            distances.append(sqrt(np.sum((x - x_predict)**2)))
        sort = np.argsort(distances)
        top=[self._y_train[i] for i in sort[:self.k]]
        votes=Counter(top)
        y_predict = votes.most_common(1)[0][0]
        return y_predict

    def predict(self,x): #多数据
        result = []
        for x1 in x:
            result.append(self._predict(x1))
        return result

    def __repr__(self):
        return  "KNN(k=%d)" %self.k