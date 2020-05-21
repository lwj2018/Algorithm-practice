/*
5. 最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    const int MAX_N = 1001;
    string longestPalindrome(string s) {
        int dp[MAX_N][MAX_N];
        int max = 0;
        int mi = 0;
        int mj = 0;
        for (int l = 1; l <= s.size(); l++)
        {
            for (int i = 0; i < s.size()-l+1; i++)
            {
                int j = i+l-1;
                if(j==i) {
                    dp[i][j] = 1;
                    if(j-i>max){
                        max = j-i;
                        mi = i;
                        mj = j;
                    }
                }
                else if(j-i==1) {
                    if(s[i]==s[j]) {
                        dp[i][j] = 1;
                        if(j-i>max) {
                            max = j-i;
                            mi = i;
                            mj = j;
                        }
                    }
                    else dp[i][j] = 0;
                }
                else if(dp[i+1][j-1]&&s[i]==s[j])
                {
                    dp[i][j] = 1;
                    if(j-i>max) {
                        max = j-i;
                        mi = i;
                        mj = j;
                    }
                }
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
        
        return s.substr(mi,mj-mi+1);
    }
};