from KMeans import KMeans, plotKmeans
import random
import numpy as np

if __name__ == '__main__':
   points = []
   data = []
   i = 0
   while i < 500:
       point = [random.randint(1, 10000), random.randint(1, 10000)]
       # 去掉重复点，否则会导致错误
       if point not in points:
           points.append(point)
           data.append(np.array(point, dtype='float64'))
           i += 1

   cluster = KMeans(data, 7)
   cluster.cluster()
   plotKmeans(cluster)
