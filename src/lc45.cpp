/*
跳跃游戏II
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

解题思路: BFS
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int steps = 0;
        while (end<nums.size()-1)
        {
            int maxReach = start + nums[start];
            for (int i = start; i <= end; i++)
            {
                if (i+nums[i]>maxReach)
                {
                    maxReach = i+nums[i];
                }
            }
            start = end + 1;
            end = maxReach;
            steps ++ ;
        }
        return steps;
    }
};