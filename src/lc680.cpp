/*
680. 验证回文字符串 Ⅱ
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        if(s.empty()) return true;
        int i = 0;
        int j = s.size()-1;
        int count = 0;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return isValid(s,i+1,j)||isValid(s,i,j-1);
            }
        }
        return true;
    }
    bool isValid(string s,int i,int j) {
        while(i<j) {
            if(s[i]==s[j]) {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};