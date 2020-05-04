/*
用N个三角形最多可以把平面分成几个区域?
递推式：s(n) = s(n-1) + 6*(n-1)
通项公式：s(n) = 3*n^2-3*n+2
*/
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int n;
    for (int i = 0; i < t; i++)
    {
        cin>>n;
        cout<<3*n*n-3*n+2<<endl;
    }
    
}