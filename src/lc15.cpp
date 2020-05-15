/*
15. 三数之和

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

这道题要注意各种边界情况！！
指针是先加一还是先进while循环很关键
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void twoSum(vector<int>& nums,int ind,int target) {
        int i = ind+1;
        int j = nums.size()-1;
        while(i<j)
        {
            if((nums[i]+nums[j])==target)
            {
                vector<int> tmp;
                tmp.push_back(-target);
                tmp.push_back(nums[i]);
                tmp.push_back(nums[j]);
                res.push_back(tmp);
                i++;
                j--;
                while(j>i&&(nums[i]==nums[i-1])) i++;
                while(j>i&&(nums[j]==nums[j+1])) j--;
            }
            if(target<nums[i]+nums[j])
            {
                j--;
                while(j>i&&(nums[j]==nums[j+1])) j--;
            }
            if(target>nums[i]+nums[j])
            {
                i++;
                while(j>i&&(nums[i]==nums[i-1])) i++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<3) return res;
        for (int i = 0; i < nums.size()-2; i++)
        {
            if(i>0){if(nums[i]==nums[i-1]) continue;}
            twoSum(nums,i,-nums[i]);
        }
        return res;
    }
};