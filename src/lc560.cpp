/*
560. 和为K的子数组
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum==k) count += 1;
            if(m[sum-k]) count += m[sum-k];
            m[sum] = m[sum]+1;
        }
        return count;
    }
};