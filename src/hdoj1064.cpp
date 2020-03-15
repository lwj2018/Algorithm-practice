#include<stdio.h>
int main()
{
    float sum;
    for (int i = 0; i < 12; i++)
    {
        float x;
        scanf("%f",&x);
        sum += x;
    }
    float mean = sum/12.0;
    printf("$%.2f\n",mean);
}