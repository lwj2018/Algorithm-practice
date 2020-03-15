#include<stdio.h>
#include<vector>
#include<ctime>
#include<iostream>
using namespace std;

const int MAX_N = 20;
int set[MAX_N+1] = {0};
unsigned long long N[MAX_N+1] = {0};

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d",v[i]);
        if (i!=v.size()-1)
        {
            printf(" ");
        }
        
    }
    printf("\n");
}

int main()
{
    int n;
    long long m;
    N[1] = 1;  
    clock_t start,end;
    for (int i = 2; i <= MAX_N; i++)
    {
        N[i] = i*N[i-1]+i;
    }
    while (scanf("%d %lld",&n,&m)!=EOF)
    {

        for (int i = 1; i <= n; i++)
        {
            set[i] = i;
        }
        
        vector<int> ans;
        start = clock();
        while (1)
        {
            if(n==1)
            {
                ans.push_back(set[1]);
                break;
            }
            int k = (m-1)/(N[n]/n)+1;
            m = m%(N[n]/n)-1;
            if (m==-1)
            {
                m=(N[n]/n)-1;
            }
            else if (m==0)
            {
                ans.push_back(set[k]);
                break;
            }
                        
            ans.push_back(set[k]);
            set[k] = set[n];
            for (int i = k; i < n-1; i++)
            {
                if (set[i]>set[i+1])
                {
                    int tmp = set[i];
                    set[i] = set[i+1];
                    set[i+1] = tmp;
                }
                
            }
            n = n-1;
        }
        
        print_vector(ans);
        end = clock();
        float deltaTime = (float) (end-start)/CLOCKS_PER_SEC;
        // cout<<"Cost: "<<1000*deltaTime<<" ms"<<endl;
    }
    
    
}