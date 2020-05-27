/*
974. 和可被 K 整除的子数组

给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        map<int,int> m;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sum += A[i];
            int key = sum%K>=0 ? sum%K:sum%K+K;
            if(key==0) res++;
            res += m[key];
            m[key]++;
        }
        return res;
    }
};
