/*
990. 等式方程的可满足性

给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。
*/
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool processEquation(string equation, unordered_map<char,int>& m, unordered_map<int,vector<char>>& m2) {
        char x = equation[0];
        char y = equation[3];
        if(equation[1]=='=') {
            if(m.count(x)) {
                if(m.count(y)) {
                    if(m[x]!=m[y]){
                        for(auto c:m2[m[y]]) {
                            m[c] = m[x];
                            m2[m[x]].push_back(c);
                        }
                    }
                }
                else {
                    m[y] = m[x];
                    m2[m[x]].push_back(y);
                }
            }
            else {
                if(m.count(y)) {
                    m[x] = m[y];
                    m2[m[y]].push_back(x);
                }
                else {
                    int s = m.size();
                    m[x] = s+1;
                    m[y] = s+1;
                    m2[s+1].push_back(x);
                    m2[s+1].push_back(y);
                }
            }
            return true;
        }
        else {
            if(m.count(x)&&m.count(y)) {
                if(m[x]==m[y]) {
                    return false;
                }
                else return true;
            }
            else {
                if(x==y) return false;
                else return true;
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char,int> m;
        unordered_map<int,vector<char>> m2;
        for(auto equation: equations) {
            if(equation[1]=='=') {
                processEquation(equation,m,m2);
            }
        }
        for(auto equation: equations) {
            if(equation[1]=='!') {
                if(!processEquation(equation,m,m2)) return false;
            }
        }
        return true;
    }
};