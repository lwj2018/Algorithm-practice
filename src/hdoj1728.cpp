#include <stdio.h>
const int MAX_M = 100;
const int MAX_N = 100;
int map[MAX_M][MAX_N] = {0};

/* direction flag:
1 left
-1 right
2 up
-2 down
*/

bool canArchive(int m,int n,int x,int y,int x2,int y2,int turn,int maxTurn,int direction)
{
    if(x<0||x>=n||y<0||y>=m)
    {
        return false;
    }
    if(map[y][x]==-1)
    {
        return false;
    }
    if(x==x2&&y==y2)
    {
        return true;
    }
    if(turn==maxTurn)
    {
        return false;
    }
    // go left
    int new_direction = 1;
    if(new_direction!=direction)
    {
        if(canArchive(m,n,x-1,y,x2,y2,turn+1,maxTurn,new_direction)) return true;
    }
    else if(new_direction!=-direction)
    {
        if(canArchive(m,n,x-1,y,x2,y2,turn,maxTurn,new_direction)) return true;
    }
    // go right
    new_direction = -1;
    if(new_direction!=direction)
    {
        if(canArchive(m,n,x+1,y,x2,y2,turn+1,maxTurn,new_direction)) return true;
    }
    else if(new_direction!=-direction)
    {
        if(canArchive(m,n,x+1,y,x2,y2,turn,maxTurn,new_direction)) return true;
    }
    // go up
    new_direction = 2;
    if(new_direction!=direction)
    {
        if(canArchive(m,n,x,y-1,x2,y2,turn+1,maxTurn,new_direction)) return true;
    }
    else if(new_direction!=-direction)
    {
        if(canArchive(m,n,x,y-1,x2,y2,turn,maxTurn,new_direction)) return true;
    }
    // go down
    new_direction = -2;
    if(new_direction!=direction)
    {
        if(canArchive(m,n,x,y+1,x2,y2,turn+1,maxTurn,new_direction)) return true;
    }
    else if(new_direction!=-direction)
    {
        if(canArchive(m,n,x,y+1,x2,y2,turn,maxTurn,new_direction)) return true;
    }
    return false;
}

void readData(int& m,int &n,int& maxTurn,int& x1,int& y1,int& x2,int& y2)
{
    scanf("%d%d",&m,&n);
    getchar();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(getchar()=='.')
            {
                map[i][j] = 1;
            }
            else
            {
                map[i][j] = -1;
            }
        }
        getchar();
    }
    scanf("%d%d%d%d%d",&maxTurn,&x1,&y1,&x2,&y2);
    return;
}

int main()
{
    int m,n;
    int x1,y1,x2,y2,maxTurn;
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        readData(m,n,maxTurn,x1,y1,x2,y2);
        if(canArchive(m,n,x1-1,y1-1,x2-1,y2-1,-1,maxTurn,0))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
}