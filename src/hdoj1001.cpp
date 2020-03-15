#include <stdio.h>

int sum(int n)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        s+=i;
    }
    return s;
}

int main()
{
    int n;
    while (scanf("%d\n",&n)!=EOF)
    {
        printf("%d\n\n",sum(n));
    }
    
}