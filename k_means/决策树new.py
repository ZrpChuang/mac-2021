# coding:utf-8
from math import log
import operator


def createDataSet():#随机建立一个数据集
    """
    传入要处理的数据集
    :return: 数据集内容，数据集标签
    """
    dataSet = [[1, 1, 'yes'],
               [1, 1, 'yes'],
               [0, 1, 'no'],
               [1, 0, 'no'],
               [1, 0, 'no']]
    labels = ['不浮出水面是否可以生存', '是否有脚蹼']
    # print(f'dataset:\n{dataSet}')
    return dataSet, labels


def calcShanonEnt(dataSet):
    """
    计算数据集的信息熵
    此处还没有乘权重
    :param dataSet:划分好的数据集
    :return:子数据集的信息熵，还没有考虑权重进来
    """

    # 数据中实例的总数
    numEntries = len(dataSet)
    # 为数据集所有可能性划分字典
    labelCounts = {}
    for featVec in dataSet:
        currentLabel = featVec[-1]
        # 如果字典中不存在，添加到字典中
        if currentLabel not in labelCounts.keys():
            labelCounts[currentLabel] = 0
        # 对存在的结果计数
        labelCounts[currentLabel] += 1
        # print(f'我是labelCounts2:\n{labelCounts}')
        # 得到{'yes': 2, 'no': 3}
    shannonEnt = 0.0
    # 此部分用于计算一个数据集的信息熵，还没有加入权重(不一定是二叉树，有几个key分支就包含几种，这里考虑到了)
    for key in labelCounts:
        prob = float(labelCounts[key]) / numEntries
        shannonEnt -= prob * log(prob, 2)
    # print(f'我是初始信息熵shannonEnt:\n{shannonEnt}')
    return shannonEnt


# 把这个数据集给写活很重要
def spliDataStet(dataSet, axis, value):
    """
    递归的思想在此处有体现，被抽出去递归的部分
    :param dataSet: 待划分的数据集
    :param axis: 划分数据集的特征
    :param value: 特征的返回值;value应该是一个变量
    :return:子数据集
    """

    retDataSet = []
    for featVec in dataSet:
        if featVec[axis] == value:
            # 除去这一元素外的其它元素组成新的数列
            """
            这里注意一下，主要卡在这里了
            """
            reducedFeatVec = featVec[:axis]
            reducedFeatVec.extend(featVec[axis + 1:])
            retDataSet.append(reducedFeatVec)
    # print(f'我是retDataSet：\n{retDataSet}')
    return retDataSet


def chooseBestFeatureToSplit(dataSet):
    """
    对于信息熵的计算
    :param dataSet:
    :return:
    """
    # 得到特征数据的长度(特征的个数) 2
    numFeatures = len(dataSet[0]) - 1
    # 原数据集的信息熵
    baseEntropy = calcShanonEnt(dataSet)
    # 定义初始的熵增益
    bestInfoGain = 0.0;
    """
    思考，好好思考一下
    """
    bestFeature = 0;
    for i in range(numFeatures):
        # 取某一列特征的值，example在此处代表列 我是featList：[1, 1, 0, 1, 1]
        featList = [example[i] for example in dataSet]
        # set集合去重取出每一特征下的所有可能情况 我是uniqueVals：{0, 1}
        uniqueVals = set(featList)
        # 定义一个变量为新的信息熵
        newEntropy = 0.0
        # 结合上方，按照某一个特征的不同value可以将数据集分割成len(uniqueVals)个子集，分割子数据集，并对子数据集求信息熵
        for value in uniqueVals:
            subDataSet = spliDataStet(dataSet, i, value)
            # print(f'我是subDataSet：\n{subDataSet}')
            # 此段代码中，prob是在某一特征分类下的权重，而self.calcShanonEnt函数计算出的为数据集的信息熵
            prob = len(subDataSet) / float(len(dataSet))
            # 得到的为按某一特征划分后的信息熵
            newEntropy += prob * calcShanonEnt(subDataSet)
        # 熵增益
        infoGain = baseEntropy - newEntropy
        # infoGain = newEntropy
        if (infoGain > bestInfoGain):
            bestInfoGain = infoGain
            bestFeature = i
    # print(f'bestFeature:\n{bestFeature}')
    return bestFeature


# 按分类后类别数量排序
def majorityCnt(classList):
    # 创建键值为classList中唯一值的数据字典，字典对象存储了classList中每个类标签出现的频率
    # 利用operator操作键值排序字典，并返回出现次数最多的分类名称
    classCount = {}
    for vote in classList:
        if vote not in classCount.keys():
            classCount[vote] = 0
        classCount[vote] += 1
    sortedClassCount = sorted(classCount.items(), key=operator.itemgetter(1), reverse=True)
    # print(f'我是sortedClassCount:\n{sortedClassCount}')
    # print(f'我是sortedClassCount:\n{sortedClassCount[0][0]}')
    return sortedClassCount[0][0]


def createTree(dataSet, labels):
    """
    构造树的过程
    :param dataSet:
    :param labels:
    :return:
    """
    classList = [example[-1] for example in dataSet]
    print(f'我是classList:\n{classList}')
    # 递归函数的第一个停止条件是所有的类标签完全相同，则直接返回该类标签
    # print(classList.count(classList[0],'==',len(classList)))
    # print(classList.count(classList[0]==len(classList)))
    if classList.count(classList[0]) == len(classList):
        """
        通过打印发现错误，第一个if判断语句的地方没有进来
        """
        print('yyyyy', classList[0])
        return classList[0]
    # 递归函数的第二个停止条件是使用完了所有特征，仍然不能将数据集划分成仅包含唯一类别的分组
    elif len(dataSet[0]) == 1:
        return majorityCnt(classList)
    # print(f'我是classList[0]:\n{classList[0]}')
    # return majorityCnt(classList[0])
    # if len(dataSet[0]) == 1:
    #     return majorityCnt(classList)
    bestFeat = chooseBestFeatureToSplit(dataSet)
    print(f'bestFeat:\n{bestFeat}')
    bestFeatLabel = labels[bestFeat]
    print(f'我是bestFeatLabel:\n{bestFeatLabel}')
    # 分类结果储存到字典中
    myTree = {bestFeatLabel: {}}
    # 在标签列表中删除最佳标签
    del (labels[bestFeat])
    # 得到最佳标签一列的所有可能特征值集合
    featValues = [example[bestFeat] for example in dataSet]
    uniqueVals = set(featValues)
    # 遍历特征值集合
    for value in uniqueVals:
        # 复印列表清单
        subLabels = labels[:]
        # 递归迭代，逐条插入字典
        myTree[bestFeatLabel][value] = createTree(spliDataStet(dataSet, bestFeat, value), subLabels)
    return myTree


if __name__ == '__main__':
    dataSet, labels = createDataSet()  # 创造示列数据
    print(createTree(dataSet, labels))  # 输出决策树模型结果


