#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> PII;

//这是一个区间合并的例题的代码
//我觉得这里有很多值得我深入学习的东西
//
//首先是c++的vector的使用
//
//还是c++ 里面排序算法的使用
//
//还有c++里面pair的使用，都是很好的例子



//核心思想是维护一个区间
void merge(vector<PII> &segs){
    vector<PII> res;

    sort(segs.begin(),segs.end());//对整个数组进行排序

    int l = -2e9,r = -2e9;
    for(int i = 0;i < segs.size();i ++){
        if(r < segs[i].first)//判断是否有重叠部分
        {
            if(r != -2e9 ) res.push_back({l,r});
            l = segs[i].first;
            r = segs[i].second;
        }
        else{
            r = max(r,segs[i].second);//没有重叠部分，返回更大值
        }
    }

    if( l != -2e9) res.push_back({l,r});

    segs = res;
}

int main(){
    int n ;
    cin >> n;

    vector<PII> segs;//定义区间集合

    for(int i = 0;i < n;i ++){
        int l,r;
        cin >> l >> r;
        segs.push_back({l,r});
    }

    merge(segs);

    cout << segs.size() << endl;

    return 0;
}