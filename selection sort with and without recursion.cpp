#include <iostream>
#include<algorithm>
using namespace std;
void selection(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
    {
        if(arr[i]>arr[j])
        swap(arr[i],arr[temp]);
    }

    }
}
void recursion_selection(int arr[],int i,int n)
{
    if(i==n)
    return;
    
    int temp=i;
    
    for(int j=i+1;j<n;j++)
    {
        if(arr[temp]>arr[j])
             temp=j;
    }
    swap(arr[i],arr[temp]);
    recursion_selection(arr,i+1,n);
}
int main()
{
    int arr[]={8,6,2,9,15,31,45,2};
    recursion_selection(arr,0,8);
    for(int i=0;i<8;i++)
    cout<<arr[i]<<"--";

    return 0;
}
