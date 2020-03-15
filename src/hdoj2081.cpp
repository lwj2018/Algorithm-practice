#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    const int len = 11;
    getchar();
    for (int i = 0; i < n; i++)
    {
        char s[len];
        for (int j = 0; j < len; j++)
        {
            scanf("%c",&s[j]);
        }
        printf("6");
        for (int j = 6; j < len; j++)
        {
            printf("%c",s[j]);
        }
        printf("\n");
        getchar();
    }
    
}