#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000;
const int MAX_M = 10000;
float h[MAX_N+1] = {0};
int a[MAX_M] = {0};
vector<int> select[MAX_N+1];
float p[MAX_M] = {0}; 

bool isIn(vector<int> v,int x)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==x)
        {
            return true;
        }
    }
    return false;
}

float solve(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        int sj = m;
        for(int j=0;j<m;j++)
        {
            if(a[j]<=i&&!isIn(select[i-a[j]],j))
            {
                if(p[j]*h[i-a[j]]<h[i])
                {
                    h[i] = p[j]*h[i-a[j]];
                    sj = j;
                }
            }
        }
        // copy
        select[i] = select[i-a[sj]];
        select[i].push_back(sj);
    }
    return 100*(1-h[n]);
}

bool readData(int& n,int &m)
{
    cin>>n>>m;
    if(n==0&&m==0)
    {
        return false;
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            cin>>a[i]>>p[i];
        }
        for(int i=0;i<m;i++)
        {
            p[i] = 1-p[i];
        }
        // clear
        for(int i=0;i<=n;i++)
        {
            h[i] = 1;
            vector<int> v;
            select[i] = v;
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
        printf("%.1f%%",solve(n,m));
    }
}