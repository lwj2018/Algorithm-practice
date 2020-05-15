/*
18. 四数之和
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void twoSum(vector<int>& nums,int ind,int n4,int n3,int target) {
        int i = ind+1;
        int j = nums.size()-1;
        while(i<j)
        {
            if((n4+n3+nums[i]+nums[j])==target)
            {
                vector<int> tmp;
                tmp.push_back(n4);
                tmp.push_back(n3);
                tmp.push_back(nums[i]);
                tmp.push_back(nums[j]);
                res.push_back(tmp);
                i++;
                j--;
                while(j>i&&(nums[i]==nums[i-1])) i++;
                while(j>i&&(nums[j]==nums[j+1])) j--;
            }
            if(target<nums[i]+nums[j]+n4+n3)
            {
                j--;
                while(j>i&&(nums[j]==nums[j+1])) j--;
            }
            if(target>nums[i]+nums[j]+n4+n3)
            {
                i++;
                while(j>i&&(nums[i]==nums[i-1])) i++;
            }
        }
    }
    void threeSum(vector<int>& nums,int ind,int n4,int target) {
        for (int i = ind+1; i < nums.size()-2; i++)
        {
            if(i>ind+1){if(nums[i]==nums[i-1]) continue;}
            twoSum(nums,i,n4,nums[i],target);
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        if(nums.size()<3) return res;
        for (int i = 0; i < nums.size()-3; i++)
        {
            if(i>0){if(nums[i]==nums[i-1]) continue;}
            threeSum(nums,i,nums[i],target);
        }
        return res;
    }
};