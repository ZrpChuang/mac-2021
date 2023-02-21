print("hello word")

import xlrd
import pandas

import xlwt

word = xlrd.open_workbook("sample.xls")
fre = xlrd.open_workbook("coca.xls")


#
table_word = word.sheets()[0]
table_fre = fre.sheets()[0]

# 创建新的workbook（其实就是创建新的excel）
workbook = xlwt.Workbook(encoding='ascii')

# 创建新的sheet表
worksheet = workbook.add_sheet("sheet 1")

# 往表格写入内容


# 保存
k = 0

for j in range(1,360):
    for i in range(1,60025):
        if i == 60024:
            worksheet.write(k, 0, table_word.row(j)[2].value)
            k += 1
            break
        if table_word.row(j)[2].value == table_fre.row(i)[2].value:
            print(table_word.row(j)[2].value,end='   ')
            print(table_fre.row(i)[2].value, end='   ')
            print(table_fre.row(i)[3].value)
            worksheet.write(k, 0, table_word.row(j)[2].value)
            worksheet.write(k, 1, table_fre.row(i)[3].value)
            k = k + 1
            break;


workbook.save("res.xls")







