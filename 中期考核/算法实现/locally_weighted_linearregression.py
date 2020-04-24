import numpy as np

class LWLR:
    def __init__(self):
        self.m = None
        self.X = None
        self.y = None
        self.theta = None

    def fit(self, X_train, y_train):
        """
        传入数据集
        :param X_train: 特征集
        :param y_train: 结果集
        :return:
        """
        assert X_train.shape[0] == y_train.shape[0]
        self.m = X_train.shape[0]
        self.X = np.hstack((np.ones((self.m, 1)), X_train))
        self.y = y_train.reshape(-1, 1)

    def predict(self, X_test, k):
        """
        预测
        :param X_test: 特征集
        :param k: 衰减因子（即权重衰减的速率）
        :return: 预测矩阵
        """
        def calculate_theta(x_test, k):
            # 构造矩阵 W
            W = np.eye(self.m, self.m)
            for i in range(self.m):
                W[i, i] = np.exp(- np.sum(np.square(self.X[i] - x_test)) / (2 * k ** 2))
            # 应用局部加权线性回归，求解 theta
            theta = np.linalg.inv(self.X.T.dot(W).dot(self.X)).dot(self.X.T).dot(W).dot(self.y)
            return theta

        def predict(x_test, k):
            theta = calculate_theta(x_test, k)
            x_test = np.insert(x_test, 0, 1)
            # y_pred = theta[0] + x_test * theta[1]
            return theta.reshape(-1, 1).dot(x_test)

        y_predict = np.empty((X_test.shape[0], ))
        for i in range(len(X_test)):
            y_predict[i] = predict(X_test[i], k)
        return y_predict