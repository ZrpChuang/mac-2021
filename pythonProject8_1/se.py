import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_excel('2.xlsx')

#读入second
data_ctit_second = data['SECONDS']

max_second = max(data_ctit_second)
min_second = min(data_ctit_second)

print(max_second)
print(min_second)


my_list = [0] * 9000

for i in range(len(data_ctit_second)):
    my_list[int(data_ctit_second[i]/10)] += 1
    print(data_ctit_second[i])
    print(int(data_ctit_second[i]/10))
#
# # 计算均值和标准差
# mean = np.mean(my_list)
# std = np.std(my_list)
#
# # 将数据标准化
# my_list = (my_list - mean) / std

x = range(len(my_list))
# plt.bar(x, my_list)
plt.plot(x, my_list)
plt.show()