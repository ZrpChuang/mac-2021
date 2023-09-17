import pandas as pd
import matplotlib.pyplot as plt

# 读取CSV文件
data = pd.read_csv('1.csv')

# 将日期时间字符串转换为日期时间对象
data['Attributed Touch Time'] = pd.to_datetime(data['Attributed Touch Time'])
data['Install Time'] = pd.to_datetime(data['Install Time'])
data['Event Time'] = pd.to_datetime(data['Event Time'])

# 绘制图形
plt.plot(data['Attributed Touch Time'], range(len(data)), label='Attributed Touch Time')
plt.plot(data['Install Time'], range(len(data)), label='Install Time')
plt.plot(data['Event Time'], range(len(data)), label='Event Time')
plt.xlabel('Time')
plt.ylabel('Frequency')
plt.title('Frequency of Events over Time')
plt.grid(True)  # 显示网格线
plt.legend()  # 显示图例
plt.xticks(rotation=45)  # 旋转x轴刻度标签，使其更易读
plt.show()