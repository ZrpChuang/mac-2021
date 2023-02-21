import numpy as np
import xlrd
import pandas
import xlwt
import matplotlib.pyplot as plt
import numpy

def cscore(t1,t2,t3,t4,t5,t6,t7,rate):
    temp = t1*(-2) + t2*(-1) + t3*3 + t4*3.5 + t5 * 5 + t6 * 7 + t7 * 10

    score = temp * 0.8 + 10 * (temp * 0.2/rate)

    return score

def grade(score):
    if score > 535:
        return 2 #表示困难
    elif score > 433:
        return 1 #表示中等
    else:
        return 0 #表示简单

book = xlrd.open_workbook("for_problem3.xls")
table = book.sheets()[0]

frt_clss = 0
scd_clss = 0
trd_clss = 0

cols = table.col_values(18)
cols = cols[2:361]
np.array(cols)

#print(cols)
i = 0
for num in cols:
    if i < 2:
        i += 1
    else:
        if num > 535:
            frt_clss += 1
        elif num > 433:
            scd_clss += 1
        else:
            trd_clss += 1

print(frt_clss)
print(scd_clss)
print(trd_clss)
sum = (frt_clss + scd_clss + trd_clss)
frt_clss = frt_clss/sum
scd_clss = scd_clss/sum
trd_clss = trd_clss/sum

edu = [frt_clss,scd_clss,trd_clss]
labels = ['Hard','Medium','Easy']
explode = [0.1, 0, 0]  #生成数据，用于凸显大专学历人群
colors = ['#9999ff', '#ff9999', '#7777aa']  #自定义颜色

plt.pie(x=edu,  #绘图数据
        explode=explode, #指定饼图某些部分的突出显示，即呈现爆炸式
        labels=labels,  #添加教育水平标签
        colors=colors,
        autopct='%.2f%%',  #设置百分比的格式，这里保留两位小数
        pctdistance=0.8,  #设置百分比标签与圆心的距离
        labeldistance=1.1,  #设置教育水平标签与圆心的距离
        startangle=180,  #设置饼图的初始角度
        radius=1.2,  #设置饼图的半径
        counterclock=False,  #是否逆时针，这里设置为顺时针方向
        wedgeprops={'linewidth':1.5, 'edgecolor':'green'},  #设置饼图内外边界的属性值
        textprops={'fontsize':10, 'color':'black'},  #设置文本标签的属性值
        )

plt.show()





