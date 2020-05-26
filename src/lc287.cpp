/*
287. 寻找重复数
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* 
方法一：快慢指针
    时间复杂度: O(n)
    空间复杂度: O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast==slow)
            {
                slow = 0;
                while(slow!=fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
            
        }
        return -1;
    }
};

/* 
二分查找
    时间复杂度: O(nlogn)
    空间复杂度: O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int l = 1;
        int r = n;
        int res = -1;
        while(l<=r) {
            int mid = (l+r)/2;
            int count = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if(nums[i]<=mid) count++;
            }
            if(count<=mid) l = mid+1;
            else {
                r = mid-1;
                res = mid;
            }
        }
        return res;
    }
};