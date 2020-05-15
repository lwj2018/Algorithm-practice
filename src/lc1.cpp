/*
1. 两数之和
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if(m[target-nums[i]]) 
            {
                res.push_back(m[target-nums[i]]-1);
                res.push_back(i);
            }
            m[nums[i]] = i+1;
        }
        return res;
    }
};