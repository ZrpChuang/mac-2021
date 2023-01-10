import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import time
'倒入各种包'

size = 1000
b = np.matrix([1 for i in range(size)]).T
U = np.eye(size, k = 1) + np.eye(size, k = 2)
L = np.eye(size, k = -1) + np.eye(size, k = -2)
U = np.matrix(U) / 2
L = np.matrix(L) / 2
D = np.eye(size)
for i in range(1, size + 1):
    D[i - 1] *= i

D = np.matrix(D)
A = U + D + L
real_x = (U + L + D).I * b
'''真的把结果给算出来了'''

def jacobi(times = 15):
    global U, L, D, b, real_x
    start_time = time.time()
    Inv_D = D.I
    M = (U + L)
    errors = []
    last_x = np.matrix(np.zeros(size)).T
    for i in range(times):
        xk = Inv_D * (b - M * last_x)
        error = np.sqrt(np.sum(np.square(xk - real_x)))
        errors.append(error)
        last_x = xk
    data = pd.DataFrame(xk)
    data.to_csv('Jacobi Result.csv')
    print(xk)
    return errors, xk, time.time() - start_time


def gaussia(times = 15):
    global U, L, D, b, real_x
    start_time = time.time()
    M = (L + D).I
    errors = []
    last_x = np.matrix(np.zeros(size)).T
    for i in range(times):
        xk = M * (b - U * last_x)
        error = np.sqrt(np.sum(np.square(xk - real_x)))
        errors.append(error)
        last_x = xk
    data = pd.DataFrame(xk)
    data.to_csv('Gaussia Result.csv')
    return errors, xk, time.time() - start_time

def sor(w = 1.1, times = 15):
    global U, L, D, b, real_x
    start_time = time.time()
    errors = []
    last_x = np.matrix(np.zeros(size)).T
    for i in range(times):
        M1 = (w * L + D).I
        M2 = (1 - w) * D * last_x - w * U * last_x
        M3 = w * (D + w * L).I * b
        xk = M1 * M2 + M3
        error = np.sqrt(np.sum(np.square(xk - real_x)))
        errors.append(error)
        last_x = xk
    data = pd.DataFrame(xk)
    data.to_csv('SOR Result.csv')
    return errors, xk, time.time() - start_time

def conjugate(times=15):
    global A, b, real_x
    start_time = time.time()
    xk = np.matrix(np.zeros(size)).T
    d = b - A * xk
    '''初始化'''
    r = b - A * xk
    errors = []
    for i in range(times):
        if np.all(np.abs(r) < 1e-20): break
        a = (r.T * r) / (d.T * A * d)
        xk = xk + (d * a)
        error = np.sqrt(np.sum(np.square(xk - real_x)))
        errors.append(error)
        last_r = r.copy()
        r = last_r - A * d * a
        B = (r.T * r) / (last_r.T * last_r)
        d = r + d * B
        '''直接按公式来'''
    data = pd.DataFrame(xk)
    data.to_csv('Conjugate Result.csv')
    return errors, xk, time.time() - start_time

def pre_conjugate(times=15):
    global A, b, D, real_x
    inv_M = D.I
    xk = np.matrix(np.zeros(size)).T
    r = b - A * xk
    d = z = inv_M * r
    errors = []
    start_time = time.time()
    for i in range(times):
        if np.all(np.abs(r) < 1e-20): break
        a = (r.T * z) / (d.T * A * d)
        xk = xk + (d * a)
        error = np.sqrt(np.sum(np.square(xk - real_x)))
        errors.append(error)
        last_r = r.copy()  # 相当于 r(k-1) 因为后面还要用到所以暂存
        r = last_r - A * d * a
        last_z = z.copy()
        z = inv_M * r
        B = (r.T * z) / (last_r.T * last_z)
        d = z + d * B
    data = pd.DataFrame(xk)
    data.to_csv('pre-Conjugate Result.csv')
    return errors, xk, time.time() - start_time


'''if __name__ == '__main__':'''
err1, res1, t1 = jacobi(15)
err2, res2, t2 = gaussia(15)
err3, res3, t3 = sor(1.25)
err4, res4, t4 = conjugate()
err5, res5, t5 = pre_conjugate()
fig = plt.figure(figsize=(8, 5))
plt.grid()
plt.xlim(0, 15)
plt.xlabel('iterator times', fontsize=20)
plt.ylabel('-log(error)', fontsize=20)
xtick = range(1, 16)
plt.xticks(xtick)
plt.plot(xtick, -np.log10(err1), marker='x')
plt.plot(xtick, -np.log10(err2), marker='x')
plt.plot(xtick, -np.log10(err3), marker='x')
plt.plot(xtick, -np.log10(err4), marker='x')
plt.plot(xtick, -np.log10(err5), marker='x')
plt.legend(['Jacobi', 'Gaussia', 'SOR', 'Conjugate', 'Con with Pre'])
plt.show()
