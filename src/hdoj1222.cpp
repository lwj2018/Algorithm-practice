/*There is a hill with n holes around. The holes are signed from 0 to n-1.
A rabbit must hide in one of the holes. A wolf searches the rabbit in anticlockwise order. The first hole he get into is the one signed with 0. Then he will get into the hole every m holes. For example, m=2 and n=6, the wolf will get into the holes which are signed 0,2,4,0. If the rabbit hides in the hole which signed 1,3 or 5, she will survive. So we call these holes the safe holes.
*/
#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if (b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}

int main()
{
    int p;
    int n,m;
    int g;
    cin>>p;
    for (int i = 0; i < p; i++)
    {
        cin>>m>>n;
        if(n>m) 
            g = gcd(n,m);
        else
        {
            g = gcd(m,n);
        }
        if (g!=1)
        {
            cout<<"YES"<<endl;
        }
        else
        {   
            cout<<"NO"<<endl;
        }        
        
    }
    
}