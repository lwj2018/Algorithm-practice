/*
136. 只出现一次的数字

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
*/
#include<map>
#include<vector>
using namespace std;
// --------------- Solution 1 --------------------
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if(!m[nums[i]]) m[nums[i]] = 1;
            else m[nums[i]] += 1;
        }
        map<int,int>::iterator iter;
        int singlenum;
        for (iter = m.begin(); iter != m.end(); iter++)
        {
            if(iter->second==1) singlenum = iter->first;
        }
        return singlenum;
    }
};
// --------------- Solution 2 --------------------
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            x ^= nums[i];
        }
        return x;
    }
};