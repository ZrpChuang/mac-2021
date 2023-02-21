def cscore(t1,t2,t3,t4,t5,t6,t7,rate):
    temp = t1*(-2) + t2*(-1) + t3*3 + t4*3.5 + t5 * 5 + t6 * 7 + t7 * 10

    score = temp * 0.8 + 10 * (temp * 0.2/rate)

    return score

def grade(score):
    if score > 568:
        return 2 #表示困难
    elif score > 433:
        return 1 #表示中等
    else:
        return 0 #表示简单