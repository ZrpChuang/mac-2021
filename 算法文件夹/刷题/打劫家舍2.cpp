// #include <iostream>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
// //这道题目其实是可以分成四种情况的，
// //首尾都选，都不选 ，选首，选尾
// //一开始的思路是选分成两类，
// //第一个选
// //第一个不选


// //后来感觉更加正确的分类应该是第一个不选，和第二个不选这两类，才能不漏

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) return nums[0];
//         if(n == 2) return max(nums[0],nums[1]);
//         int res = 0;
//         vector<int> dp(n + 1);

//         //假设第一个第一个位置不选
//         dp[0] = 0;dp[1] = max(nums[1],dp[0]);
//         for(int i = 2;i < n; i ++ ){
//             dp[i] = max(dp[i - 1],dp[i - 2] + nums[i]);//选取更加大的值
//         }

//         res = dp[n - 1];

//         //假设最后一个位置不选
//         dp[0] = nums[0];dp[1] = max(nums[1],dp[0]);
//         for(int i = 2;i < n - 1; i ++ ){
//             dp[i] = max(dp[i - 1],dp[i - 2] + nums[i]);//选取更加大的值
//         }
//         res = max(res,dp[n - 2]);

//         return res;
//     }
// };