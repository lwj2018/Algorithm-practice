/*
面试题46. 把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> toVector(int num) {
        vector<int> res;
        if(num==0) {
            res.push_back(0);
            return res;
        }
        while(num) {
            res.insert(res.begin(),num%10);
            num = num/10;
        }
        return res;
    }
    int translateNum(int num) {
        vector<int> v = toVector(num);
        vector<int> dp(v.size()+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = dp[i-1];
            if(v[i-2]!=0&&v[i-2]*10+v[i-1]<26) dp[i] += dp[i-2];
        }
        return dp.back();
    }
};