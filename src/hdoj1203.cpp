// Be careful to the boundary condition n=0 & m=0 !!!!
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000;
const int MAX_M = 10000;
double h[2][MAX_N+1] = {0};
int a[MAX_M] = {0};
double p[MAX_M] = {0};

double solve(int n,int m)
{
    for(int i=0;i<m;i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j>=a[i])
            {
                h[1][j] = max(p[i]+h[0][j-a[i]]-p[i]*h[0][j-a[i]],h[0][j]);
            }
            else
            {
                h[1][j] = h[0][j];
            }
            
        }
        for (int j = 1; j <= n; j++)
        {
            h[0][j] = h[1][j];
        }
    }
    return 100*(h[0][n]);
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
            h[0][i] = 0;
            h[1][i] = 0;
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