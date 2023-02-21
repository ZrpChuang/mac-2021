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

cols_1 = table.col_values(6)
cols_1 = cols_1[2:361]
np.array(cols_1)

cols_2 = table.col_values(7)
cols_2 = cols_2[2:361]
np.array(cols_2)

cols_3 = table.col_values(8)
cols_3 = cols_3[2:361]
np.array(cols_3)

cols_4 = table.col_values(9)
cols_4 = cols_4[2:361]
np.array(cols_4)

cols_5 = table.col_values(10)
cols_5 = cols_5[2:361]
np.array(cols_5)

cols_6 = table.col_values(11)
cols_6 = cols_6[2:361]
np.array(cols_6)

cols_7 = table.col_values(12)
cols_7 = cols_7[2:361]
np.array(cols_7)

for i in range(12):
    cols_x = [1, 2, 3, 4, 5, 6, 7]
    cols_y = [cols_1[i]/100, cols_2[i]/100, cols_3[i]/100, cols_4[i]/100, cols_5[i]/100, cols_6[i]/100, cols_7[i]]
    plt.title("normal distribution")
    plt.xlabel("tries")
    plt.ylabel("num")
    plt.plot(cols_x, cols_y)





plt.show()