/*
152. 乘积最大子数组

给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max = nums[0];
        int cur = 1;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            cur *= nums[i];
            if (cur>max)
            {
                max = cur;
            }
            if(cur==0) cur = 1;
        }
        cur = 1;
        for (int i = n-1; i >= 0; i--)
        {
            cur *= nums[i];
            if (cur>max)
            {
                max = cur;
            }
            if(cur==0) cur = 1;
        }
        return max;
    }
};