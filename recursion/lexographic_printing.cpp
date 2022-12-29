#include <iostream>

using namespace std;
void dfs(int i,int n)
{
    if(i>n)
    return;
    cout<<i<<" ";
    for(int j=0;j<=9;j++)
    {
        dfs(10*i+j,n);
    }
}
int main()
{
     for(int i=1;i<=9;i++)
    {
        dfs(i,1000);
        cout<<endl;
    }

    return 0;
