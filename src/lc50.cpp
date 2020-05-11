/*
50. Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数
*/
#include <cmath>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double square(double x)
    {
        return x*x;
    }
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        if (n==2)
        {
            return square(x);
        }
        if (n%2==0)
        {
            if(n>0) return square(myPow(x,n/2));
            else return 1/square(myPow(x,-(n/2)));
        }
        else
        {
            if(n>0) return square(myPow(x,n/2))*x;
            else return 1/(square(myPow(x,-(n/2)))*x);
        }
        
    }
};