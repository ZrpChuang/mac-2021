#创建数据集
def createdataset():
    dataSet=[[0,2,0,0,'N'],
            [0,2,0,1,'N'],
            [1,2,0,0,'Y'],
            [2,1,0,0,'Y'],
            [2,0,1,0,'Y'],
            [2,0,1,1,'N'],
            [1,0,1,1,'Y'],
            [0,1,0,0,'N'],
            [0,0,1,0,'Y'],
            [2,1,1,0,'Y'],
            [0,1,1,1,'Y'],
            [1,1,0,1,'Y'],
            [1,2,1,0,'Y'],
            [2,1,0,1,'N'],]
    labels=['age','income','job','credit']
    return dataSet,labels


ds1,lab = createdataset()
print(ds1)
print(lab)


def calcShannonEnt(dataSet):
    numEntries = len(dataSet)
    labelCounts = {}
    for featVec in dataSet:
        currentLabel = featVec[-1]
        if currentLabel not in labelCounts.keys():
            labelCounts[currentLabel] = 0

        labelCounts[currentLabel] += 1

    shannonEnt = 0.0
    for key in labelCounts:
        prob = float(labelCounts[key]) / numEntries
        shannonEnt -= prob * log(prob, 2)

    return shannonEnt

shan = calcShannonEnt(ds1)
print(shan)


