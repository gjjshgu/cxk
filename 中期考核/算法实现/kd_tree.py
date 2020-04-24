import numpy as np
# from sklearn.datasets import load_iris
# from sklearn.model_selection import train_test_split

class KDNode:
    def __init__(self, data=None, label=None, left=None, right=None, axis=None, parent=None):
        """
        KD树节点定义
        :param data: 特征数据
        :param label: 结果数据
        :param left: 左孩子
        :param right: 右孩子
        :param axis: 分割线
        :param parent: 父节点
        """
        self.data = data
        self.left = left
        self.right = right
        self.label = label
        self.axis = axis
        self.parent = parent

class KDTree:
    def __init__(self, X, y=None):
        """
        KD树
        :param X: 特征集
        :param y: 结果集，默认为空
        """
        self.root = None
        self.y_exist = False if y is None else True
        self.create(X, y)

    def create(self, X, y=None):
        def _create(X, axis, parent=None):
            """
            递归创建KD树
            :param X: 特征集
            :param axis: 分割线
            :param parent: 父节点
            :return:
            """
            nums = X.shape[0]
            if nums == 0: return None
            mid = (nums >> 1)
            index = np.argsort(X[:, axis])
            small = np.array([X[i] for i in index[:mid]])
            big = np.array([X[i] for i in index[mid+1:]])
            if self.y_exist:
                kd_node = KDNode(X[index[mid]][:-1], X[mid][-1], axis=axis, parent=parent)
            else:
                kd_node = KDNode(X[index[mid]], axis=axis, parent=parent)

            next_axis = (axis + 1) % k_dimensions
            kd_node.left = _create(small, next_axis, kd_node)
            kd_node.right = _create(big, next_axis, kd_node)
            return kd_node

        k_dimensions = X.shape[1]
        print("正在创建KD树......")
        if y is not None:
            X = np.hstack((X, y.reshape(-1, 1)))
        self.root = _create(X, 0)
        print("创建完毕")

    def search_k(self, k, point, ord=2):
        """
        寻找k个最邻近点
        :param k: k个点
        :param point: 目标点
        :param ord: 范数，默认是L2范数（欧氏距离）
        :return:
        """
        def dist(x):
            """
            计算x与point的距离
            :param x: 计算点
            :return:
            """
            return np.linalg.norm(x-point, ord=ord)

        def axis_distance(node):
            """
            计算当前点与分割线的距离
            :param node:
            :return:
            """
            return abs(node.data[node.axis] - point[node.axis])

        def update(node, distance):
            """
            更新最邻近点
            :param node: 节点
            :param distance: 距离
            :return:
            """
            nonlocal count, nodes
            if len(count) < k:
                count.append(distance)
                nodes.append(node)
            elif len(count) == k:
                max_index = np.argmax(count)
                if distance < count[max_index]:
                    count[max_index] = distance
                    nodes[max_index] = node

        def _search(node):
            """
            传入节点，递归搜索
            :param node: 搜索节点
            :return:
            """
            nonlocal count, nodes
            if node is None: return
            distance = dist(node.data)
            update(node, distance)
            if point[node.axis] < node.data[node.axis]:
                _search(node.left)
            else:
                _search(node.right)
            rang = axis_distance(node)
            if rang > np.max(count):
                return
            if point[node.axis] < node.data[node.axis]:
                _search(node.right)
            else:
                _search(node.left)
        count = []
        nodes = []
        _search(self.root)
        x = np.array([i.data for i in nodes])
        y = np.array([int(i.label) for i in nodes]) if self.y_exist is True else None
        return x, y

    def predict(self, X_test, k):
        """
        预测
        :param X_test: 预测数据集
        :param k: k个邻近点
        :return:
        """
        assert self.y_exist is True
        m = X_test.shape[0]
        y_pr = np.empty(m)
        for i in range(m):
            _x, y = self.search_k(k, X_test[i])
            y_pr[i] = y[np.argmax(np.bincount(y))]
        return y_pr

# if __name__ == '__main__':
#     X = load_iris().data
#     y = load_iris().target
#     X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)
#     kdt = KDTree(X_train, y_train)
#     y_predict = kdt.predict(X_test, 13)
#     print(np.sum(y_predict == y_test)/len(y_test))