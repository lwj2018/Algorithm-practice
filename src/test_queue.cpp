#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
    queue<int*> x;
    int x1[2] = {0,0};
    int x2[2] = {1,1};
    int x3[2] = {2,2};
    x.push(x1);
    int * front = x.front();
    cout<<*front<<" "<<*(front+1)<<endl;
    x.push(x2);
    front = x.front();
    cout<<*front<<" "<<*(front+1)<<endl;
    x.push(x3);
    front = x.front();
    cout<<*front<<" "<<*(front+1)<<endl;
    
}