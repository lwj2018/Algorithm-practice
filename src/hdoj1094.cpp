#include <stdio.h>
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d",&x);
            s += x;
        }
        printf("%d\n",s);
    }
    
    
}