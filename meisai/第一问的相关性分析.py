import numpy as np
import xlrd
import pandas as pd
import xlwt
import matplotlib.pyplot as plt
import numpy
from scipy.stats import pearsonr

book = xlrd.open_workbook("for_problem3.xls")
table = book.sheets()[0]


cols_rate = table.col_values(16)
cols_rate = cols_rate[2:361]
np.array(cols_rate)#获取比例数据

cols_rate = (cols_rate - np.min(cols_rate))/(np.max(cols_rate) - np.min(cols_rate))


cols_fre = table.col_values(0)
cols_fre = cols_fre[2:361]
np.array(cols_fre)
cols_fre = (cols_fre - np.min(cols_fre))/(np.max(cols_fre) - np.min(cols_fre))

cols_letter = table.col_values(17)
cols_letter = cols_letter[2:361]
np.array(cols_letter)#获取比例数据

cols_letter = (cols_letter - np.min(cols_letter))/(np.max(cols_letter) - np.min(cols_letter))


df = pd.DataFrame({"word frequency":cols_fre,"percentage":cols_rate,"latter":cols_letter})

def GetPvalue_Pearson(x,y):
    return pearsonr(x,y)[1]

df.corr(method='spearman')

# df.corr(method="pearson")
r = pearsonr(df["latter"],df["percentage"])
print("pearson：",r[0])
print("   P-Value：",r[1])


pd.plotting.scatter_matrix(df)
plt.show()