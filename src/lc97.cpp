/*
97. 交错字符串
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
*/
#include<iostream>
#include<string>
using namespace std;
#define max(a,b) a>b?a:b
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        if (l1+l2!=l3)
        {
            return false;
        }
        
        bool dp[1000][1000];
        dp[0][0] = true;
        for (int i = 1; i <= l1; i++)
        {
            dp[i][0] = dp[i-1][0]&&s1[i-1]==s3[i-1];
        }
        for (int i = 1; i <= l2; i++)
        {
            dp[0][i] = dp[0][i-1]&&s2[i-1]==s3[i-1];
        }
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                bool flag1 = dp[i-1][j]&&(s1[i-1]==s3[i+j-1]);
                bool flag2 = dp[i][j-1]&&(s2[j-1]==s3[i+j-1]);
                dp[i][j] = flag1||flag2;
            }
            
        }
        return dp[l1][l2];
    }
};

int main()
{
    Solution sol = Solution();
    string s1 = "";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    sol.isInterleave(s1,s2,s3);
}
