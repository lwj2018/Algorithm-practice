#include <stdio.h>
#include <queue>
const int MAX_M = 100;
const int MAX_N = 100;
int map[MAX_M][MAX_N] = {0};
int color[MAX_M][MAX_N] = {0};
using namespace std;

typedef struct point
{
    int x,y,turn;
}point;

int direction[4][2] = {-1,0,1,0,0,-1,0,1};

bool bfs(int m,int n,int x1,int y1,int x2,int y2,int maxTurn)
{
    queue<point> q;
    point start,end;
    start.x = x1;
    start.y = y1;
    start.turn = -1;
    color[y1][x1] = 1;
    q.push(start);
    while(q.size()!=0)
    {
        point cur = q.front();
        q.pop();
        if (cur.turn>maxTurn)
        {
            continue;
        }
        
        if (cur.x==x2&&cur.y==y2)
        {
            return true;
        }
        end.turn = cur.turn+1;
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x;
            int ny = cur.y;
            while (1)
            {
                nx += direction[i][0];
                ny += direction[i][1];
                if(map[ny][nx]==-1||nx<0||nx>=n||ny<0||ny>=m)
                {
                    break;
                }
                if (color[ny][nx]==0)
                {
                    color[ny][nx]=1;
                    end.x = nx;
                    end.y = ny;
                    q.push(end);
                }
            }
            
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