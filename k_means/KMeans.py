import random
import sys
import numpy as np
import matplotlib.pyplot as plt

class KMeans(object):

   def __init__(self, input_data, k):
       # data是一个包含所有样本的numpy数组
       # data示例，每行是一个坐标
       # [[1 2],
       #  [2 3],
       #  [3 4]]
       self.data = input_data
       self.k = k
       # 保存聚类中心的索引和类样本的索引
       self.centers = []
       self.clusters = []
       self.capacity = len(input_data)
       self.__pick_start_point()

   def __pick_start_point(self):
       # 随机确定初始簇心
       self.centers = []
       if self.k < 1 or self.k > self.capacity:
           raise Exception("K值错误")
       indexes = random.sample(np.arange(0, self.capacity, step=1).tolist(), self.k)
       for index in indexes:
           self.centers.append(self.data[index])

   def __distance(self, i, center):
       diff = self.data[i] - center
       return np.sum(np.power(diff, 2))**0.5

   def __calCenter(self, cluster):
       # 计算该簇的中心
       cluster = np.array(cluster)
       if cluster.shape[0] == 0:
           return False
       return (cluster.T @ np.ones(cluster.shape[0])) / cluster.shape[0]

   def cluster(self):
       changed = True
       while changed:
           self.clusters = []
           for i in range(self.k):
               self.clusters.append([])
           for i in range(self.capacity):
               min_distance = sys.maxsize
               center = -1
               # 寻找簇
               for j in range(self.k):
                   distance = self.__distance(i, self.centers[j])
                   if min_distance > distance:
                       min_distance = distance
                       center = j
               # 加入簇
               self.clusters[center].append(self.data[i])
           newCenters = []
           for cluster in self.clusters:
               newCenters.append(self.__calCenter(cluster).tolist())
           if (np.array(newCenters) == self.centers).all():
               changed = False
           else:
               self.centers = np.array(newCenters)

def plotKmeans(cluster):
   xdata = []
   ydata = []
   for Cluster in cluster.clusters:
       xsubdata = []
       ysubdata = []
       for point in Cluster:
           xsubdata.append(point[0])
           ysubdata.append(point[1])
       xdata.append(xsubdata)
       ydata.append(ysubdata)

   colors = ['r', 'g', 'b', 'c', 'm', 'y', 'k']
   for i in range(len(xdata)):
       for j in range(len(xdata[i])):
           x = np.array([xdata[i][j], cluster.centers[i][0]])
           y = np.array([ydata[i][j], cluster.centers[i][1]])
           plt.plot(x, y,
                    color=colors[i],  # 全部点设置为红色
                    marker='o',  # 点的形状为圆点
                    ms=7,
                    linestyle='-')
       plt.plot([cluster.centers[i][0]], [cluster.centers[i][1]],
                color=colors[i],  # 全部点设置为红色
                marker='*', ms=20,  # 点的形状为圆点
                linestyle='-')
       plt.scatter(cluster.centers[i][0], cluster.centers[i][1], s=350, c='none',
                   alpha=0.7, linewidth=1.5, edgecolor=colors[i])
   plt.grid(True)
   plt.title("K-means")
   plt.show()
