import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import xlrd
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

# 1.造数据
df = pd.DataFrame()
df["percentage"] = cols_rate
df["score"] = cols_letter

# 2.相关分析热力图可视化, df.corr()默认参数为pearson
plt.figure(figsize=[10, 6])
sns.heatmap(df.corr(method='spearman'), vmin=0, vmax=1, cmap="Reds", linewidths=0.5, annot=True)
plt.show()
