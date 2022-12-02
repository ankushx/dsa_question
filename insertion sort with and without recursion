#include <iostream>

using namespace std;
void insertion(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            if(arr[j]>temp)
            arr[j+1]=arr[j];
            else
            break;
        }
        arr[j+1]=temp;
    }
}
void recursion_insertion(int arr[],int i,int n)
{
    if(i==n)
    return;
    
    int temp=arr[i];
    int j=i-1;
    for(;j>=0;j--)
    {
        if(temp<arr[j])
        arr[j+1]=arr[j];
        else
        break;
    }
    arr[j+1]=temp;
    recursion_insertion(arr,i+1,n);
}
int main()
{
    int arr[]={8,6,2,9,15,31,45,2};
    recursion_insertion(arr,1,8);
    for(int i=0;i<8;i++)
    cout<<arr[i]<<"--";

    return 0;
}
