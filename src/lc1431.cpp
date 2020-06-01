/*
1431. 拥有最多糖果的孩子

给你一个数组 candies 和一个整数 extraCandies ，其中 candies[i] 代表第 i 个孩子拥有的糖果数目。

对每一个孩子，检查是否存在一种方案，将额外的 extraCandies 个糖果分配给孩子们之后，此孩子有 最多 的糖果。注意，允许有多个孩子同时拥有 最多 的糖果数目。
*/
#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = -1;
        vector<bool> can(candies.size(),false);
        for (int i = 0; i < candies.size(); i++)
        {
            if(candies[i]>max) max = candies[i];
        }
        for (int i = 0; i < can.size(); i++)
        {
            if(candies[i]+extraCandies>=max) can[i] = true;
        }
        return can;
    }
};