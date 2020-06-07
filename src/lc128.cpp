/*
128. 最长连续序列

给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            if(m.find(n)==m.end()) {
                int left = 0;
                int right = 0;
                if(m.find(n-1)!=m.end()) left = m[n-1];
                if(m.find(n+1)!=m.end()) right = m[n+1];
                int curLength = left+1+right;
                maxLength = curLength > maxLength ? curLength : maxLength;
                m[n-left] = curLength;
                m[n+right] = curLength;
                m[n] = curLength;
            }
        }
        return maxLength;
    }
};