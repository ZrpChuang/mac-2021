import numpy as np
import xlrd
import pandas
import xlwt
import matplotlib.pyplot as plt
import numpy



book = xlrd.open_workbook("for_problem3.xls")
table = book.sheets()[0]

frt_clss = 0
scd_clss = 0
trd_clss = 0

cols = table.col_values(17)
cols = cols[2:361]
np.array(cols)

for i in range(350):
    if cols[i] > 650:
        cols[i] = cols[i-1]
#     if cols[i] <0.014:
#         cols[i] = cols[i-1]
a = 0
b = 0
c = 0
d = 0
e = 0
f = 0
for i in range(350):
    if i<100:
        a += cols[i]
    elif i<200:
        b += cols[i]
    elif i<300:
        c += cols[i]

print(a)
print(b)
print(c)
print(d)
print(e)
print(f)


cols_x = range(1,360)
np.array(cols)

plt.title("score of letter")
plt.xlabel("times")
plt.ylabel("score")

plt.plot(cols_x,cols)
plt.show()