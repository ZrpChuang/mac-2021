import pandas as pd
import pickle
from fbprophet import Prophet

# 读取数据
df = pd.read_csv('data.csv')

# Prophet模型的输入格式要求是一个包含两列的DataFrame，第一列是时间戳，第二列是待预测值（即时间序列数据）
df = df.rename(columns={'date': 'ds', 'value': 'y'})

# 创建Prophet模型
model = Prophet()

# 设置24小时一个周期的季节性
model.add_seasonality(name='hourly', period=24, fourier_order=15)

# 拟合模型
model.fit(df)

# 预测未来24小时的值
future_dates = model.make_future_dataframe(periods=24, freq='H')
forecast = model.predict(future_dates)

# 保存模型到本地文件中
with open('prophet_model.pkl', 'wb') as f:
    pickle.dump(model, f)

# 从本地文件中加载模型
with open('prophet_model.pkl', 'rb') as f:
    loaded_model = pickle.load(f)

# 使用已加载的模型进行预测
future_dates = loaded_model.make_future_dataframe(periods=24, freq='H')
forecast = loaded_model.predict(future_dates)

# 展示预测结果
loaded_model.plot(forecast)