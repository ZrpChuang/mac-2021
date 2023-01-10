import numpy as np

size=10

'''try = np.eye(4 ,k = 1)'''

b = np.matrix([1 for i in range(size)]).T
U = np.eye(size, k = 0)+ np.eye(size, k = 2)
print(U)
L = np.eye(size, k = -1) + np.eye(size, k = -2)
U = np.matrix(U) / 2
L = np.matrix(L) / 2
D = np.eye(size)

