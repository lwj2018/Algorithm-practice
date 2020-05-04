/*2007年到来了。经过2006年一年的修炼，数学神童zouyu终于把0到100000000的Fibonacci数列
(f[0]=0,f[1]=1;f[i] = f[i-1]+f[i-2](i>=2))的值全部给背了下来。
接下来，CodeStar决定要考考他，于是每问他一个数字，他就要把答案说出来，不过有的数字太长了。所以规定超过4位的只要说出前4位就可以了，可是CodeStar自己又记不住。于是他决定编写一个程序来测验zouyu说的是否正确。
*/
#include<iostream>
#include<cmath>
using namespace std;
const int N = 20;
int f[N] = {0};
const double c = (1+sqrt(5))/2;
int fib4(int n)
{
    double f = log10(1/sqrt(5)) + n*log10(c);
    f = f - int(f);
    f = pow(10,f);
    return (int)(f*1000);
}

int main()
{
    int n;
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < N; i++)
    {
        f[i] = f[i-1]+f[i-2];
    }
    
    while(scanf("%d",&n)!=EOF)
    {
        if(n<N) cout<<f[n]<<endl;
        else cout<<fib4(n)<<endl;
    }
}