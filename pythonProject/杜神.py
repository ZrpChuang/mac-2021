import math
from math import *
import numpy as np
from numpy import arccos
import matplotlib.pyplot as plt
import mpl_toolkits.axisartist as axisartist
import pandas as pd
plt.rcParams['font.sans-serif']=['SimHei']
plt.rcParams['axes.unicode_minus'] = False


def even(n):
    # if n == 10:
    #    xlist = [-1, -0.8, -0.6, -0.4, -0.2, 0, 0.2, 0.4, 0.6, 0.8, 1]
    gap = float(2 / n)
    xlist = list(range(n))
    for i in range(n):
        xlist[i] = -1 + gap * i
    return xlist


def Chebyshev(n):
    xlist = list(range(n))
    for i in range(1, n + 1, 1):
        xlist[i - 1] = cos((2 * i - 1) / (2 * n) * math.pi)
    return xlist


def Newton(xlist, n):
    fmatrix = [[0 for i in range(50)] for i in range(50)]
    for i in range(n):
        fmatrix[n][i] = e ** (-2 * xlist[i])
    for i in range(n):
        print((fmatrix[n][i]))
    for i in range(n - 1, 0, -1):
        for j in range(i):
            fmatrix[i][j] = (fmatrix[i + 1][j + 1] - fmatrix[i + 1][j]) / float(xlist[j + n - i] - xlist[j])  # 2/n
    clist = list(range(n))
    for i in range(n):
        clist[i] = fmatrix[n - i][0]
    fxlist = list(range(n))
    ylist = list(range(n))

    for w in range(n):  # w是枚举计算第几个插值的点
        y = 0
        x = xlist[w]  # x用来保存xlist[w]这个纵坐标值
        for k in range(w + 1):  # 将0~w的多项式系数记录下来
            fxlist[k] = clist[k]
        for i in range(w + 1):  # 枚举多项式的每一项来计算
            for j in range(i):  # 枚举多项式每一项的次数
                fxlist[i] *= (x - xlist[j])  # 即c×(x-xi)^t
            y += fxlist[i]  # 累加总y值
        ylist[w] = y  # 第w个点插值多项式的值
    print(ylist)
    return ylist


def intererror(xlist_1, xlist_2):  # list_1是0.05步长，xlist_2是切比雪夫选点
    error = list(range(n + 1))
    for i in range(n + 1):
        error[i] = math.exp(-2 * xlist_1[i])  # 初始化为e^(-2x)
        for j in range(i):  # 求导n次
            error[i] *= (-2)  # 每求一次导就相当于乘上-2
    for i in range(n + 1):  # 枚举每一个步长选点，来计算误差
        for val in xlist_2:  # 乘上x和每一个切比雪夫插值点横坐标的差(x-x_i)
            error[i] *= (xlist_1[i] - val)
        for val in range(1, n + 1):  # 除n!
            error[i] /= val
        error[i] = abs(error[i])
    data = pd.DataFrame(error)  # 创建数据
    data.to_csv('Error.csv')  # 加入表格
    print(error)
    return error


def Plot(xlist_1, ylist_1, xlist_2, ylist_2, error):
    plt.grid()
    plt.xticks(np.linspace(-1, 1, 20))
    plt.yticks(np.linspace(0, 7, 20))
    plt.plot(
        xlist_1,
        ylist_1,
        label=' Newton’s divided difference formula with evenly space',
        color='red')
    plt.xticks(np.linspace(-1, 1, 20))
    plt.yticks(np.linspace(0, 7, 20))
    plt.plot(
        xlist_2,
        ylist_2,
        label=' Newton’s divided difference formula with Chebyshev point',
        color='blue')
    fig1 = plt.figure(figsize=(6, 4))  # 新建画布
    ax = axisartist.Subplot(fig1, 111)  # 使用axisartist.Subplot方法创建一个绘图区对象ax
    fig1.add_axes(ax)  # 将绘图区对象添加到画布中
    plt.grid()
    plt.plot(
        xlist_1,
        error,
        label=' Newton’s divided error with evenly space',
        color='blue')
    plt.show()


if __name__ == '__main__':
    n = int(input('Please enter number of n : '))
    n = n + 1
    xlist_1 = even(n)
    ylist_1 = Newton(xlist_1, n)
    n = n - 1
    xlist_2 = Chebyshev(n)
    ylist_2 = Newton(xlist_2, n)
    error = intererror(xlist_1, xlist_2)
    Plot(xlist_1, ylist_1, xlist_2, ylist_2, error)