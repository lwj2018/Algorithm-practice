#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;

const int MAX_N = 10;
const int MAX_M = 10;
int map[MAX_N][MAX_M] = {0};
int color[MAX_N][MAX_M] = {0};
int tt[MAX_N][MAX_M] = {0};

typedef struct Node
{
    int x,y,d,t;
}Node;

int bfs(Node start,int n,int m)
{
    queue<Node> q;
    q.push(start);
    while(q.size()!=0)
    {
        Node cur = q.front();
        q.pop();
        bool reset=false;
        if(map[cur.x][cur.y]==3&&cur.t>0)
        {
            return cur.d;
        }
        else if(map[cur.x][cur.y]==4&&cur.t>0)
        {
            cur.t = 6;
            reset = true;
        }
        color[cur.x][cur.y] = 1;
        tt[cur.x][cur.y] = cur.t;
        Node next;
        next.t = cur.t-1;
        next.d = cur.d+1;

        if(map[cur.x][cur.y]!=0&&cur.t>0)
        {
            if(cur.x-1>=0)
            {
                next.x = cur.x-1;
                next.y = cur.y;
                q.push(next);
            }
            if(cur.x+1<n)
            {
                next.x = cur.x+1;
                next.y = cur.y;
                q.push(next);
            }
            if(cur.y-1>=0)
            {
                next.x = cur.x;
                next.y = cur.y-1;
                q.push(next);
            }
            if(cur.y+1<m)
            {
                next.x = cur.x;
                next.y = cur.y+1;
                q.push(next);
            }
        }
        if(reset) map[cur.x][cur.y] = 0;
    }
    return -1;
}

void readData(Node &start,int &n,int &m)
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
            tt[i][j] = 0;
            if(map[i][j] == 2)
            {
                start.x = i;
                start.y = j;
                start.t = 6;
                start.d = 0;
            }
        }
    }

}

int main()
{
    int n,m;
    int N;
    Node start;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        readData(start,n,m);
        printf("%d\n",bfs(start,n,m));
    }
}