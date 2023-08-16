from flask import Flask, request, jsonify
from keras.models import load_model
import datetime
import random

app = Flask(__name__)
model = load_model('model.h5')

@app.route('/ctit', methods=['GET'])
def predict_time():
    # 获取请求中的参数
    a = request.json['a']
    a = int(request.args.get('a'))

    # 进行预测
    res = []
    for i in range(a):
        x = [(3344/a)*i + 3344/a*2]
        y_pred = model.predict(x)
        gen = y_pred[0][0] * 10 + random.randint(1, 10)
        res.append(int(gen))

    # 将所有秒数转换为时间格式
    seconds = res
    times = []
    for s in seconds:
        td = datetime.timedelta(seconds=s)
        times.append(str(td))

    # 返回结果
    return jsonify(times)

if __name__ == '__main__':
    app.run(debug=True)