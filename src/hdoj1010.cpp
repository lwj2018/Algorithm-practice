// Be careful, it's quite easy to exceed the time limit for this problem
// You should minimize the number of judgements
#include <stdio.h>
#include <iostream>
using namespace std;

const int MAX_N = 10;
const int MAX_M = 10;
char map[MAX_N][MAX_M];
int color[MAX_N][MAX_M]={0};

int direction[4][2] = {-1,0,1,0,0,-1,0,1};
bool success = false;

void dfs(int x,int y,int n,int m,int d,int t)
{
    if (d>t)
    {
        return;
    }
    else if (map[x][y]=='D'&&d==t)
    {
        success = true;
        return;
    }

    if (map[x][y]=='.'||map[x][y]=='S')
    {
        color[x][y] = 1;
        int nx,ny;
        if (color[x-1][y]==0&&x-1>=0)
        {
            dfs(x-1,y,n,m,d+1,t); 
        }
        if (color[x+1][y]==0&&x+1<n)
        {
            dfs(x+1,y,n,m,d+1,t); 
        }
        if (color[x][y-1]==0&&y-1>=0)
        {
            dfs(x,y-1,n,m,d+1,t); 
        }
        if (color[x][y+1]==0&&y+1<m)
        {
            dfs(x,y+1,n,m,d+1,t); 
        }
        
        color[x][y] = 0;       
    }
    
    return;
    
}

int main()
{
    int x,y,n,m,t;
    while (cin>>n>>m>>t&&(n+m+t))
    {
        for(int i=0;i<n;i++)
        {
            cin>>map[i];
            for(int j=0;j<m;j++)
            {
                if (map[i][j]=='S')
                {
                    x = i;
                    y = j;
                }
                                
                // clear color
                color[i][j] = 0;
            }
        }
        success = false;
        dfs(x,y,n,m,0,t);
        if (success)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        
        
    }
    
}