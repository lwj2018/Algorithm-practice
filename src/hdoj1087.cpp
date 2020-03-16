#include <stdio.h>

const int MAX_N = 1000;
int s[MAX_N] = {0};

int getMaxSum(int x[],int n)
{
    // clear
    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        int xx = x[i];
        int maxSum = 0;
        for (int j = 0; j < i; j++)
        {
            if (x[j]<xx&&s[j]+xx>maxSum)
            {
                maxSum = s[j]+xx;
            }
            
        }
        if (xx>maxSum)
        {
            maxSum = xx;
        }
        s[i] = maxSum;
        
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i]>max)
        {
            max = s[i];
        }
        
    }
    
    return max;
    
}

int main()
{
    int x[MAX_N] = {0};
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
        {
            break;
        }
        
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&x[i]);
        }
        printf("%d\n",getMaxSum(x,n));
    }
    
}