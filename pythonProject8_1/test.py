import pandas as pd
import matplotlib.pyplot as plt

# 读取CSV文件
# data = pd.read_csv('1.csv')
data = pd.read_excel('2.xlsx')

print(data['Attributed Touch Time'][0])
#
# # 将日期时间字符串转换为日期时间对象

# diff = data['SECONDS'] #zhe
# diff = [x for x in diff]
# diff_len = len(diff)
#
# print(diff_len)
#
# x = range(59940)
# y = diff
#
# plt.plot(x, y)
# plt.show()

#先把同一天的柱状图给画出来

datalist = pd.to_datetime(data['Attributed Touch Time'])


a = []
date = datalist[0].strftime("%d")
temp = 0
num = 0

for i in range(1,59940):
    if date == datalist[i].strftime("%d"):
        temp += data['SECONDS'][i]
    else:
        date = datalist[i].strftime("%d")
        a.append(temp)
        temp = 0

print(len(a))
print(len(range(1,len(a) + 1)))
x =  range(1,len(a) + 1)
plt.bar(x, a)
plt.show()

print(a)

#把二小时的时间段画出来



# data['Install Time'] = pd.to_datetime(data['Install Time'])
# #
# # # 计算时间差
# data['Time Difference'] = (data['Install eTime'] - data['Attributed Touch Time']).astype(str)
# #
# # # 显示结果
# print(data['Time Difference'].tolist())
#
# import pandas as pd
# import numpy as np
# from scipy.stats import linregress

# # 读取CSV文件
# data = pd.read_csv('1.csv')
#
# # 将日期时间字符串转换为日期时间对象
# data['Attributed Touch Time'] = pd.to_datetime(data['Attributed Touch Time'])
# data['Install Time'] = pd.to_datetime(data['Install Time'])
#
# # 线性回归拟合
# x1 = np.arange(len(data))
# x2 = np.arange(len(data))
# y1 = data['Attributed Touch Time'].values.astype(np.int64) // 10**9  # 将时间转换为秒级的时间戳
# y2 = data['Install Time'].values.astype(np.int64) // 10**9
#
# slope1, intercept1, _, _, _ = linregress(x1, y1)
# slope2, intercept2, _, _, _ = linregress(x2, y2)
#
# # 输出方程
# equation1 = f'y = {slope1:.2f}x + {intercept1:.2f}'
# equation2 = f'y = {slope2:.2f}x + {intercept2:.2f}'
#
# print("Attributed Touch Time 方程:", equation1)
# print("Install Time 方程:", equation2)

# import pandas as pd
# import numpy as np
# import matplotlib.pyplot as plt
# from scipy.stats import linregress

# # 读取CSV文件
# data = pd.read_csv('1.csv')

# # 将日期时间字符串转换为日期时间对象
# data['Attributed Touch Time'] = pd.to_datetime(data['Attributed Touch Time'])
# data['Install Time'] = pd.to_datetime(data['Install Time'])

# # 计算ctit时间并转换为秒级时间戳
# ctit = (data['Attributed Touch Time'] - data['Install Time']).dt.total_seconds()

# # 线性回归拟合ctit时间
# x_ctit = np.arange(len(ctit))
# y_ctit = ctit.values.astype(np.int64) // 109

# slope_ctit, intercept_ctit, _, _, _ = linregress(x_ctit, y_ctit)

# # 输出ctit方程
# equation_ctit = f'ctit = {slope_ctit:.2f}x + {intercept_ctit:.2f}'
# print("CTIT 方程:", equation_ctit)

# # 画出ctit时间序列及线性回归线
# plt.plot(x_ctit, y_ctit, label='CTIT')
# plt.plot(x_ctit, slope_ctit*x_ctit + intercept_ctit, 'r', label='CTIT Linear Regression')
# plt.xlabel('Index')
# plt.ylabel('CTIT (seconds)')
# plt.legend()
# plt.show()