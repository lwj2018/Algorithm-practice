#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000;
const int MAX_M = 10000;
double h[MAX_N+1] = {0};
int a[MAX_M] = {0};
double p[MAX_M] = {0};

double solve(int n,int m)
{
    for(int i=0;i<m;i++)
        for (int j = n; j >= a[i]; j--)
            h[j] = max(p[i]+h[j-a[i]]-p[i]*h[j-a[i]],h[j]);
    return 100*(h[n]);
}

bool readData(int& n,int &m)
{
    scanf("%d%d",&n,&m);
    if(n==0&&m==0)
    {
        return false;
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d%lf",&a[i],&p[i]);
        }
        // clear
        for(int i=0;i<=n;i++)
        {
            h[i] = 0;
        }
    }
    return true;
}

int main()
{
    int n,m;
    while(1)
    {
        if(!readData(n,m))
        {
            break;
        }
        printf("%.1lf%%\n",solve(n,m));
    }
}