from keras.models import Sequential
from keras.layers import Dense
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from datetime import datetime, timedelta

data = pd.read_excel('2.xlsx')

for index, row in data.iterrows():
    if row['Campaign'] != 'ms_14581':
        data = data.drop(index)

# 读入点击时间
data_ATT = data['Attributed Touch Time']
data_IT = data['Install Time']

data_ATT = pd.to_datetime(data_ATT)
data_IT = pd.to_datetime(data_IT)

delta = data_IT - data_ATT

seconds = []

for d in delta:
    seconds.append(d.total_seconds())

print('max',max(seconds))


# 打包处理好的数据
import scipy.io as sio
import matplotlib.pyplot as plt


sio.savemat('seconds.mat', {'seconds': seconds}) #
sio.savemat('data_ATT.mat', {'data_ATT': data_ATT})


# # 从mat文件中加载数据
# x = sio.loadmat('x.mat')
#
# # 将变量转换为Python列表
# x = x['x'].tolist()
#
# # 从mat文件中加载数据
# y = sio.loadmat('y.mat')
#
# # 将变量转换为Python列表
# y = y['y'].tolist()
#
# x = np.array(x)
# y = np.array(y)
#
# x = x.reshape(-1)
# y = y.reshape(-1)
#
# print(max(x))
# print(min(x))
