#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int lis(int a[],int n)
{
    int i,j,arr[n+1];
    for(i=0;i<n;i++)
    {
        arr[i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i] && arr[i]<arr[j]+1)
                arr[i]=arr[j]+1;
        }
    }
    int mx=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>mx)
            mx=arr[i];
    }
    return mx;
}

int main()
{
    int n,i;
    cout<<"Enter Array size";
    cin>>n;
    int a[n+1];
    cout<<"Enter elements of array";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=lis(a,n);
    cout<<ans<<"\n";
}

