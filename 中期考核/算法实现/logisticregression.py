import numpy as np
import pandas as pd
# from sklearn.datasets import load_iris
# from sklearn.model_selection import train_test_split


class LogisticRegression:
    def __init__(self):
        self.theta=None
        self.m=None
        self.n=None

    def fit(self,X_train,y_train,eta=0.01,n_iters=1e5,epslion=1e-7):
        """
        :param X_train: 训练特征集
        :param y_train: 训练结果集
        :param eta: 学习率
        :param n_iters: 最大循环次数
        :param epslion: 接近0的数，判断梯度下降是否进行完全
        :return:
        """
        assert X_train.shape[0]==y_train.shape[0]

        def h(X,theta):
            res=X.dot(theta)
            return 1 / (1+np.exp(-res))

        def J(X,y,theta):
            res=y*np.log10(h(X,theta))+(1-y)*np.log10(1-h(X,theta))
            return -(np.sum(res) / self.m)

        def dJ(X,theta):
            beta=h(X,theta) - (y_train)
            res=(X.T).dot(beta)
            return res / self.m

        self.m = X_train.shape[0]
        self.n = X_train.shape[1]
        theta = np.zeros(X_train.shape[1]).reshape(-1, 1)
        y_train = y_train.reshape(-1, 1)
        for _ in range(int(n_iters)):
            gredient = dJ(X_train, theta)
            last_theta = theta
            theta = theta-eta*gredient
            if (abs(J(X_train,y_train,theta)-J(X_train,y_train,last_theta))<epslion):
                break

        self.theta = theta
        return self

    def _predict(self,X_test):
        assert self.theta is not None
        res = X_test.dot(self.theta)
        res = 1 / (1+np.exp(-res))
        # res[res > 0.5] = 1
        # res[res < 0.5] = 0
        return np.squeeze(res)

    def predict(self, X_test):
        res = self._predict(X_test)
        res[res > 0.5] = 1
        res[res < 0.5] = 0
        return res

class one_vs_all:
    def __init__(self):
        self.theta = None

    def fit(self, X_train, y_train, eta=0.01, n_iters=1e4, epslion=1e7):
        """
        :param X_train: 训练特征集
        :param y_train: 训练结果集
        :param eta: 学习率
        :param n_iters: 最大循环次数
        :param epslion: 接近0的数，判断梯度下降是否进行完全
        :return:
        """
        y_train = np.array(pd.get_dummies(y_train))
        features = y_train.shape[1]
        self.theta = np.empty((features, X_train.shape[1]))
        for i in range(features):
            lr = LogisticRegression()
            lr.fit(X_train, y_train[:, i], eta, n_iters, epslion)
            # print(lr.predict(X_train))
            # print(np.sum(lr.predict(X_train) == y_train[:, i])/len(X_train))
            # a =X_train.dot(lr.theta)
            # print(a)
            self.theta[i] = np.squeeze(lr.theta)


    def predict(self, X_test):
        # res = []
        # for i in self.theta:
        #     res.append(np.squeeze(X_test.dot(i.reshape(-1, 1))))
        # res = np.array(res)
        # res = 1 / (1 + np.exp(-res))
        # res[res > 0.5] = 1
        # res[res < 0.5] = 0
        # return np.argmax(res, axis=0)

        res = self.theta.dot(X_test.T)
        res = 1 / (1 + np.exp(-res))
        res[res > 0.5] = 1
        res[res < 0.5] = 0
        return np.argmax(res, axis=0)

# if __name__ == '__main__':
#     iris = load_iris()
#     X = iris.data
#     y = iris.target
#     # y[y == 2] = 0
#     X_train,X_test,y_train,y_test = train_test_split(X, y, test_size=0.2)
#     clf = one_vs_all()
#     clf.fit(X_train, y_train)
#     print(clf.predict(X_test))
#     print(np.sum(clf.predict(X_test) == y_test) / len(y_test))