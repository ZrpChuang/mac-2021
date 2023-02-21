from matplotlib.ticker import FuncFormatter

from getexcel import getcol,getexcelstr
from writeexcel import writecol
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
def y_update_scale_value(temp, position):
    result = temp
    return "{}%".format(float(result))
def for_other():
    label = ["Improved-BLS", "SVM", "Random Forest"]
    test1_acc = [88.89, 85.12, 76.22]
    test2_acc = [80.67, 75.43, 75.51]
    test3_acc = [71.62, 70.23, 64.55]
    x = np.arange(len(label))  # x轴刻度标签位置
    width = 0.2  # 柱子的宽度
    # 计算每个柱子在x轴上的位置，保证x轴刻度标签居中
    plt.figure(figsize=(10, 6))
    plt.gca().yaxis.set_major_formatter(FuncFormatter(y_update_scale_value))  # 设置y1轴单位
    plt.bar(x - 1 * width, test1_acc, width, label='threshold=0.5')
    plt.bar(x + 0 * width, test2_acc, width, label='threshold=0.4')
    plt.bar(x + 1 * width, test3_acc, width, label='threshold=0.3')
    plt.ylabel('Scores')
    plt.title('Comparison of three methods')
    # x轴刻度标签位置不进行计算
    plt.xticks(x, labels=label, rotation=-15)
    plt.legend()
    plt.show()
    return 1
def barof2():
    label = ["1 try", "2 tries", "3 tries", "4 tries", "5 tries", "6 tries", "7 more tries"]
    actual_acc = [0,0.02,0.10,0.19,0.19,0.23,0.26]
    test_acc = [0,0.04,0.20,0.35,0.27,0.11,0.02]

    x = np.arange(len(label))  # x轴刻度标签位置
    # 计算每个柱子在x轴上的位置，保证x轴刻度标签居中
    plt.figure(figsize=(10, 6))
    plt.gca().yaxis.set_major_formatter(FuncFormatter(y_update_scale_value))  # 设置y1轴单位
    plt.bar(x, actual_acc, width=0.9, color='deepskyblue', label='actual distribution')
    plt.bar(x, test_acc, width=0.75, label='predicted distribution')
    plt.ylim(0, 1)
    plt.ylabel('Percetage')
    # plt.title('Comparison of three methods')
    # x轴刻度标签位置不进行计算
    plt.legend()
    plt.show()
def barof1():
    label = ["1 try", "2 tries", "3 tries", "4 tries", "5 tries", "6 tries", "7 more tries"]
    actual_acc = [0,0.05,0.17,0.37,0.31,0.09,0.01]
    x = np.arange(len(label))  # x轴刻度标签位置
    # 计算每个柱子在x轴上的位置，保证x轴刻度标签居中
    plt.figure(figsize=(10, 6))
    # plt.gca().yaxis.set_major_formatter(FuncFormatter(y_update_scale_value))  # 设置y1轴单位
    plt.bar(x, actual_acc, width=0.9, color='lightseagreen')
    # for a, b, i in zip(label, actual_acc, range(len(label))):  # zip 函数
    #     plt.text(a, b + 0.01, actual_acc[i], ha='center')  # plt.text 函数

    plt.ylim(0, 1)
    plt.ylabel('Percetage')
    plt.title('predicted distribution of \'ERIEE\'')
    # x轴刻度标签位置不进行计算
    plt.legend()
    plt.show()

def numberdate():
    date = getexcelstr()
    numbers = getcol(4)
    df1 = pd.DataFrame(numbers, index=date, columns=['number of reported results'])
    print(df1)
    df1['number of reported results'].plot()
    plt.title('number of reported results')
    plt.plot(df1, color='cornflowerblue')
    plt.xticks(rotation=-15)
    plt.show()
def syllable():
    syllable = getcol(12,'./副本属性汇总.xlsx')
    score1 = 0
    score2 = 0
    score3 = 0
    for i in syllable:
        if i==1:
            score1=score1+1
        elif i==2:
            score2=score2+1
        else:
            score3=score3+1
    # -*- coding: utf-8 -*-
    width = 0.99  # 柱子的宽度
    score_1=[score1]
    score_2=[score2]
    score_3=[score3]
    label1=["one syllable"]
    label2=["two syllables"]
    label3=["three syllbales"]
    plt.bar(label1, score_1, color='lightseagreen', width=width)
    plt.bar(label2, score_2, color='gold', width=width)
    plt.bar(label3, score_3, color='cornflowerblue', width=width)
    plt.show()
def cixing():
    cixing = getcol(14, './副本属性汇总.xlsx')
    score1 = 0
    score2 = 0
    score3 = 0
    score4 = 0
    score5 = 0
    for i in cixing:
        if i == 1:
            score1 = score1 + 1
        elif i == 2:
            score2 = score2 + 1
        elif i == 3:
            score3 = score3 + 1
        elif i == 4:
            score4 = score4 + 1
        else:
            score5 = score5 + 1
    # -*- coding: utf-8 -*-
    width = 0.9  # 柱子的宽度
    score_1 = [score1]
    score_2 = [score2]
    score_3 = [score3]
    score_4 = [score4]
    score_5 = [score5]
    label1 = ["noun"]
    label2 = ["verbs"]
    label3 = ["Pronoun"]
    label4 = ["Adjectives"]
    label5 = ['adverbs']
    plt.bar(label1, score_1, color='lightseagreen', width=width)
    plt.bar(label2, score_2, color='gold', width=width)
    plt.bar(label3, score_3, color='cornflowerblue', width=width)
    plt.bar(label4, score_4, color='red', width=width)
    plt.bar(label5, score_5, color='blue', width=width)
    plt.show()
def repeat():
    syllable = getcol(12, './副本属性汇总.xlsx')
    score1 = 0
    score2 = 0
    score3 = 0
    for i in syllable:
        if i == 1:
            score1 = score1 + 1
        elif i == 2:
            score2 = score2 + 1
        else:
            score3 = score3 + 1
    # -*- coding: utf-8 -*-
    width = 0.99  # 柱子的宽度
    score_1 = [score1]
    score_2 = [score2]
    score_3 = [score3]
    label1 = ["one syllable"]
    label2 = ["two syllables"]
    label3 = ["three syllbales"]
    plt.bar(label1, score_1, color='lightseagreen', width=width)
    plt.bar(label2, score_2, color='gold', width=width)
    plt.bar(label3, score_3, color='cornflowerblue', width=width)

if __name__ == "__main__":
    # cixing()
    # for_other()
    barof1()