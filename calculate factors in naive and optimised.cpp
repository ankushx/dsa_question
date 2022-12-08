#include<bits/stdc++.h>
using namespace std;
void factor(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        cout<<i<<" ";
    }
}
void Optimised_factor(int n)
{
    for(int i=1;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
            cout<<n/i<<" ";
        }
    }
}
int main()
{
   int n=64;
   factor(n);
   Optimised_factor(n);

    return 0;
}
