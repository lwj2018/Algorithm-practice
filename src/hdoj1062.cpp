#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
void reverse_print(vector<char> s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        printf("%c",s[n-i-1]);
    }
    return;
}
void print(vector<char> s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        printf("%c",s[i]);
    }
    return;
}
int main()

{
    int n;
    scanf("%d",&n);
    // read the first \n
    getchar();
    for (int i = 0; i < n; i++)
    {
        vector<char> s;
        while(1)
        {
            char c = getchar();
            if(c==' ')
            {
                reverse_print(s);
                printf(" ");
                s.clear();
            }
            else if(c=='\n')
            {
                reverse_print(s);
                printf("\n");
                s.clear();
                break;
            }
            else
            {
                s.push_back(c);
            }
        }
    }
    
}