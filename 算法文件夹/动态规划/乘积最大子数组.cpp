//
// Created by zrp on 2023/1/25.
//

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int res = nums[0];//贪心
//         int f = nums[0],g = nums[0];
//         for(int i = 1;i < nums.size() ;i ++ ){
//             int temp_f = f * nums[i];
//             int temp_g = g * nums[i];
//             f = max(temp_f,nums[i]);
//             f = max(f,temp_g);
//             g = min(temp_f,nums[i]);
//             g = min(g,temp_g);
//             res = max(f,res);
//         }
//         return res;
//     }
// };