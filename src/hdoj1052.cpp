/*Tian Ji -- The Horse Racing*/
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

const int MAX_N = 1000;
int T[MAX_N] = {0};
int K[MAX_N] = {0};

bool readData(int &n)
{
    cin>>n;
    if(n==0) return false;
    for(int i=0;i<n;i++)
    {
        cin>>T[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>K[i];
    }
    return true;
}

int solve(int n)
{
    sort(T,T+n);
    sort(K,K+n);
    int ts = n-1;
    int ks = n-1;
    int te = 0;
    int ke = 0;
    int win = 0;
    int lose = 0;
    while (n--)
    {
        if(T[te]>K[ke])
        {
            win++;
            te++;
            ke++;
        }
        else if(T[ts]>K[ks])
        {
            win++;
            ts--;
            ks--;
        }
        else if(T[te]<K[ks])
        {
            lose++;
            te++;
            ks--;
        }
    }
        
    return (win-lose)*200;
}


int main()
{
    int n;
    
    while (readData(n))
    {
        int maxVal = solve(n);
        cout<<maxVal<<endl;
    }
    
}