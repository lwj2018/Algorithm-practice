/*
76. 最小覆盖子串

给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

各种过不了边界情况，结果把代码改的非常丑 TAT
*/
#include <cmath>
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        map<char,int> m1;
        map<char,int> m2;
        int l = 0;
        int r = s.size()-1;
        int ml = 0;
        int mr = s.size()-1;
        for (int i = 0; i < s.size(); i++)
        {
            m1[s[i]] ++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            m2[t[i]] ++;
        }
        for (r = s.size()-1; r >= 0; r--)
        {
            char x = s[r];
            if(m1[x]-1<m2[x]) break;
            else m1[x]--;
        }
        for (l = 0; l < s.size(); l++)
        {
            char x = s[l];
            if(m1[x]-1<m2[x]) break;
            else m1[x]--;
        }
        if(r-l<mr-ml)
        {
            ml = l;
            mr = r;
        }
        for (int i = 0; i <= t.size(); i++)
        {
            if(m1[t[i]]<m2[t[i]]) return "";
        }
        while(l<r&&r<s.size()-1)
        {
            char find;
            while(l<r&&l<s.size())
            {
                char x = s[l];
                m1[x] --;
                l++;
                if(m1[x]<m2[x]){ 
                    find = x;
                    break;
                }
            }
            if(r<s.size()-1) r++;
            while(r<s.size())
            {
                char x = s[r];
                m1[x] ++;
                if(x==find) break;
                r++;
            }
            if(r==s.size()) break;
            while(l<r)
            {
                char x = s[l];
                if(m1[x]-1<m2[x]){ 
                    break;
                }
                m1[x] --;
                l++;
            }
            if(r<s.size()&&r-l<mr-ml)
            {
                ml = l;
                mr = r;
            }
        }
        return s.substr(ml,mr-ml+1);
    }
};