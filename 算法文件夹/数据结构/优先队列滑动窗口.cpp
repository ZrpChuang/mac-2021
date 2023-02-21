// #include <iostream>
// #include <algorithm>

// using namespace std;


// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> res;
//         int n = nums.size();//数组总大小
//         int q[n + 10];//优先队列
//         int hh = 0,tt = -1;

//         for(int i = 0; i < k; i ++ ){
//             while(hh <= tt && nums[q[tt]] < nums[i]) tt --;
//             q[ ++ tt] = i;
//         }//出一个，之后每步出一个

//         res.push_back(nums[q[hh]]);

//         for(int i = k;i < n;i ++ ){
//             if(hh <= tt && q[hh] <= i - k) hh ++;
//             while(hh <= tt && nums[q[tt]] < nums[i] ) tt--;
//             q[ ++ tt] = i;
//             res.push_back(nums[q[hh]]);
//         }
//         return res;
//     }
// };


/*
对于多重背包问题，效率最高的算法就只利用单调队列来优化。这道题目的单调队列相对而言会更加简便。

基本思路：
定义一个vector，或者就是数组，作为队列；
其实状态为空，就用hh = 0，tt = -1 表示（其中hh是head，tt是tail）；

我的做法是：
先对前k个元素进行处理，相当于是初始队列状态；
对给定的nums数组剩余元素进行遍历，没遍历一个元素都会对队列进行维护，从而产生一个队头元素输出到res中；

维护的方式：
    1.检查队列是否为空&&队头元素是否符合窗口大小要求
    2.针对每一个队尾元素，小于等于当前值则t-- 出队；
    3.然后最新元素加在队尾。

*/