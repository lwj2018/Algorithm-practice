/*
9. 回文数

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        };
        int y = 0;
        int tmp = x;
        while(tmp) {
            int remain = tmp%10;
            y = y*10 + remain;
            tmp = tmp/10;
        }
        return y==x;
    }
};