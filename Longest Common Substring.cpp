#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll l[100][100];
string s1,s2,s;
ll mx=0,indx,indy;
/*program for longest common substring , outputs number of common subsequence and the common string */
//driver code
//Time Complexity: O(m*n)
//Auxiliary Space: O(m*n)
ll lcsubstring(ll m,ll n)
{
    ll i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 ||j==0)
                l[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                {
                    l[i][j]=l[i-1][j-1]+1;
                    if(l[i][j]>mx)
                    {
                        mx=l[i][j];
                        indy=i;
                        indx=j;
                    }
                }
            else
                l[i][j]=0;
        }
    }
    return mx;
}
//prints the substring
void prts()
{
    while(l[indy][indx]!=0)
    {
        s=s1[indy-1]+s;
        indy=indy-1;
        indx=indx-1;
    }
    cout<<s;
}
int main()
{
    cin>>s1>>s2;
    s='\0';
    ll m=s1.size();
    ll n=s2.size();
    ll ans=lcsubstring(m,n);
    cout<<ans<<"\n";//length of longest common substring
    prts();//print substring
    return 0;
}

