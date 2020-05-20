/*
1371. 每个元音包含偶数次的最长子字符串

给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。
*/
#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int state = 0x0;
        map<int,int> m;
        int max = 0;
        m[state] = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='a') state ^= 0x00001;
            else if(s[i]=='e') state ^= 0x00010;
            else if(s[i]=='i') state ^= 0x00100;
            else if(s[i]=='o') state ^= 0x01000;
            else if(s[i]=='u') state ^= 0x10000;
            if(m.count(state)==0) m[state] = i+1;
            else if(i+1-m[state]>max) max = i+1-m[state];
        }
        return max;
    }
};