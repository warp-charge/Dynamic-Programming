#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//----------------------------------------------------
//recursion tree will be formed
//lots of overlapping subproblems
/*int fib(int n)
{
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}*/
//------------------------------------------------------

//two ways to overcome overlapping subproblems
//-------------------------------------------------------
//1>MEMOIZATION (TOP DOWN APPROACH)
//initialize lookup table to NIL(-1)
/*
int lookup[MAX];
void init()
{
    int i;
    for(i=0;i<MAX;i++)
        lookup[i]=-1;
}
int fib(int n)
{
    if(lookup[n]==-1)
    {
        if(n<=1)
            lookup[n]=n;
        else
            lookup[n]=fib(n-1)+fib(n-2);
    }
    return lookup[n];
}*/
//------------------------------------------------------

//------------------------------------------------------
//2>TABULATION (BOTTOM UP APPROACH)
//builds a table in bottom up fashion
ll fib(int n)
{
    ll f[n+1],i;
    f[0]=0;
    f[1]=1;
    for(i=2;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}
//------------------------------------------------------

int main()
{
   ll t,n,i;
   //init();
   t=5;
   while(t--)
   {
   cin>>n;
   cout<<fib(n)<<"\n";
   }
}
