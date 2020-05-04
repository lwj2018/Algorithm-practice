/*The Joseph's problem is notoriously known. For those who are not familiar with the original problem: from among n people, numbered 1, 2, . . ., n, standing in circle every mth is going to be executed and only the life of the last remaining person will be saved. Joseph was smart enough to choose the position of the last remaining person, thus saving his life to give us the message about the incident. For example when n = 6 and m = 5 then the people will be executed in the order 5, 4, 6, 2, 3 and 1 will be saved.

Suppose that there are k good guys and k bad guys. In the circle the first k are good guys and the last k bad guys. You have to determine such minimal m that all the bad guys will be executed before the first good guy. 
*/
#include<iostream>
using namespace std;
int a[250] = {0};

int solve(int k)
{
    if (a[2*k])
    {
        return a[2*k];
    }
    
    bool flag;
    int m;
    for (int r = 0; ; r++)
    {
        for (int h = k+1; h <= 2*k; h++)
        {
            flag = true;
            m = r*2*k + h;
            int f=0;
            int i;
            for (i = 1; i <= k; i++)
            {
                f = (f + m-1)%(2*k-i+1);
                if (0<=f&&f<k)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (a[2*k]==0)
    {
        a[2*k] = m;
    }
    
    return m;

}

int main()
{
    int k;
    cin>>k;
    while (k!=0)
    {
        cout<<solve(k)<<endl;
        cin>>k;
    }
    
}