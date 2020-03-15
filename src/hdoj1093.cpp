#include <stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        int n;
        scanf("%d",&n);
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