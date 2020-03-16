#include <stdio.h>
const int MAX_M = 100;
const int MAX_N = 100;
int map[MAX_M][MAX_N] = {0};
int color[MAX_M][MAX_N] = {0};
int q[MAX_M*MAX_N][4] = {0};
int start = 0;
int end = 0;
using namespace std;

/* direction flag:
0 left
1 right
2 up
3 down
*/

void push(int x,int y,int turn,int direction)
{
    q[end][0] = x;
    q[end][1] = y;
    q[end][2] = turn;
    q[end][3] = direction;
    end = end+1;
    if(end>=MAX_M*MAX_N) end = 0;
}

void pop()
{
    start = start+1;
    if(start>=MAX_M*MAX_N) start = 0;
}

bool isEmpty()
{
    return (start==end);
}

void clear()
{
    for (int i = 0; i < MAX_N*MAX_M; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            q[i][j] = 0;
        }
        
    }
    
}

bool bfs(int m,int n,int x1,int y1,int x2,int y2,int maxTurn)
{
    push(x1,y1,-1,-1);
    while(!isEmpty())
    {
        int x = q[start][0];
        int y = q[start][1];
        int turn = q[start][2];
        int direction = q[start][3];
        pop();
        color[y][x] = 1;
        if (x==x2&&y==y2)
        {
            return true;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int new_direction = i;
            int new_turn = turn;
            if(new_direction!=direction)
            {
                new_turn = turn+1;
                if (new_turn > maxTurn)
                {
                    continue;
                }
                
            }
            int new_x = x;
            int new_y = y;
            switch (i)
            {
            case 0:
                new_x = x-1;
                break;
            case 1:
                new_x = x+1;
                break;
            case 2:
                new_y = y-1;
                break;
            case 3:
                new_y = y+1;
                break;            
            default:
                break;
            }
            if (map[new_y][new_x]==-1||color[new_y][new_x]==1)
            {
                continue;
            }
            if (new_x<0||new_x>=n||new_y<0||new_y>=m)
            {
                continue;
            }
            push(new_x,new_y,new_turn,new_direction);
        }
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
            // clear color
            color[i][j] = 0;
            // clear queue
            clear();
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
        if(bfs(m,n,x1-1,y1-1,x2-1,y2-1,maxTurn))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
}