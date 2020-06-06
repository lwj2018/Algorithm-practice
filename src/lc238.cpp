/* 
238. 除自身以外数组的乘积

给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1;
        int right = 1;
        vector<int> out(nums.size(),0);
        for (int i = 0; i < nums.size(); i++)
        {
            out[i] = left;
            left *= nums[i];
        }
        for (int i = nums.size()-1; i >= 0; i--)
        {
            out[i] = out[i] * right;
            right *= nums[i];
        }
        return out;
    }
};