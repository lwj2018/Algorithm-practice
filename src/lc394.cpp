/*
394. 字符串解码

给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

struct node {
    string s;
    int n;
    node(int n): n(n) {}
};

class Solution {
public:
    int stoi(vector<int> x) {
        int n = 0;
        int decade = 1;
        for (int i = 0; i < x.size(); i++)
        {
            n += decade*x[i];
            decade *= 10;
        }
        return n;
    }
    string decodeString(string s) {
        string res = "";
        vector<int> x;
        stack<node> myStack;
        int i = 0;
        while(i<s.size()) {
            if(s[i]<='9'&&s[i]>='0') {
                x.insert(x.begin(),s[i]-'0');
            }
            else if(s[i]=='[') {
                node myNode(stoi(x));
                myStack.push(myNode);
                x.clear();
            }
            else if(s[i]==']') {
                int n = myStack.top().n;
                string clip = myStack.top().s;
                myStack.pop();
                string tmp;
                for (int j = 0; j < n; j++) {
                    tmp += clip;
                }
                if (myStack.empty()) {
                    res += tmp;
                }
                else {
                    myStack.top().s += tmp;
                }
            }
            else if(myStack.empty()) {
                res += s[i];
            }
            else if(!myStack.empty()) {
                myStack.top().s += s[i];
            }
            i++;
        }
        return res;
    }
};