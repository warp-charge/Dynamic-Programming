#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//given two strings s1,s2 and below operations that can be performed on
//s1. Find minimum number of edits(operations) required to convert 's1' into 's2'
//a>INSERT b>REMOVE c>REPLACE

//DP Approach
//Bottom up manner
//Time Complexity: O(n1 x n2)
//Auxiliary Space: O(n1 x n2)
int editDist(string s1,string s2,int n1,int n2)
{
    int dp[n1+1][n2+1],i,j;
    for(i=0;i<=n1;i++)
    {
        for(j=0;j<=n2;j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];

            else
                dp[i][j]=1+min(dp[i][j-1],    //Insert
                               min(dp[i-1][j],//Remove
                                   dp[i-1][j-1]));//Replace

        }
    }
    return dp[n1][n2];

}

int main()
{
    string s1,s2;
    s1="sunday";
    s2="saturday";
    int n1,n2;
    n1=s1.length(); n2=s2.length();
    cout<<"minimum no. of edits is "<<editDist(s1,s2,n1,n2);
    return 0;
}
