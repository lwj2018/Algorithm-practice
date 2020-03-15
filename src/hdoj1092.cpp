#include <stdio.h>
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d",&x);
            s+=x;
        }
        printf("%d\n",s);
    }
    
}