from keras.models import Sequential
from keras.layers import Dense
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import scipy.io as sio
import pickle
from keras.models import load_model
import random



# x = sio.loadmat('x.mat')

# 将变量转换为Python列表
# x = x['x'].tolist()

# 从mat文件中加载数据
# y = sio.loadmat('y.mat')

# 将变量转换为Python列表
# y = y['y'].tolist()

# x = np.array(x)
# y = np.array(y)
#
# x = x.reshape(-1)
# y = y.reshape(-1)
a = 30
x = [a]
# 创建多层感知机模型
# model = Sequential()
# model.add(Dense(units=64, activation='relu', input_dim=1))
# model.add(Dense(units=64, activation='relu'))
# model.add(Dense(units=1, activation='linear'))
# model.compile(loss='mean_squared_error', optimizer='adam')

# 训练模型
# model.fit(x, y, epochs=200, batch_size=10, verbose=0)

# 保存模型到本地文件
# 保存模型到本地文件
# model.save('model.h5')

# 加载保存的模型
model = load_model('model.h5')

# 进行预测
res = []
for i in range(a):
    x = [(3344/a)*i + 3344/a*2]
    y_pred = model.predict(x)
    gen = y_pred[0][0] * 10 + random.randint(1, 10)
    res.append(int(gen))

print(res)

import datetime

# 定义一个包含秒数的列表
seconds = res

# 将所有秒数转换为时间格式
times = []
for s in seconds:
    td = datetime.timedelta(seconds=s)
    times.append(str(td))

# 输出结果
print(times)