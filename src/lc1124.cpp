/*
1124. 表现良好的最长时间段

给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。

我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。
*/
#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
// ---------------- Hash Map ------------------------
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        map<int,int> m;
        m[0] = 0;
        int sum = 0;
        int max = 0;
        for (int i = 0; i < hours.size(); i++)
        {
            if(hours[i]>8) sum++;
            else sum--;
            if(sum>0) max = i+1;
            if(m.count(sum)==0){
                m[sum] = i+1;
            }
            if(m.count(sum-1)>=1) {
                if(i+1-m[sum-1]>max)
                    max = i+1-m[sum-1];
            }
        }
        return max;
    }
};
// ------------------ 单调栈 --------------------------
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        stack<int> s;
        vector<int> vSum(hours.size()+1,0);
        vSum[0] = 0;
        int sum = 0;
        int max = 0;
        s.push(0);
        for (int i = 0; i < hours.size(); i++)
        {
            if(hours[i]>8) sum++;
            else sum--;
            vSum[i+1] = sum;
            if(s.empty() || sum<vSum[s.top()]) s.push(i+1);
        }
        for (int i = hours.size()-1; i >= 0; i--)
        {
            while(vSum[i+1]>vSum[s.top()])
            {
                s.pop();
            }
            if(i+1-s.top()>max) max = i+1-s.top();
        }
        
        return max;
    }
};
