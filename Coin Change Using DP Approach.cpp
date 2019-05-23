#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//----------------------------------------------------------------------
//1> Optimal Substructure
//To count the total number of solutions, we can divide all set solutions into two sets.
//    >Solutions that do not contain mth coin (or Sm).
//    >Solutions that contain at least one Sm.
//2>Overlapping Subproblems
//recursion tree

//DP Approach
//Tabulation bottom up approach
//personal opinion solution like 01 knapsack
//O(m*n)
int count(int coins[],int m,int n)
{
    int i,j,x,y;
    int dp[m][n+1];

    // Fill the entries for 0 value case (n = 0)
    for(i=0;i<m;i++)
    {
        dp[i][0]=1;
    }
    // Fill rest of the table entries in bottom up manner
    for(i=0;i<m;i++)
    {
        for(j=1;j<=n;j++)
        {
            // Count of solutions including coins[j]
            x=j-coins[i]>=0?dp[i][j-coins[i]]:0;

            // Count of solutions excluding coins[j]
            y=(i>=1)?dp[i-1][j]:0;

            // total count
            dp[i][j]=x+y;
        }
    }
    return dp[m-1][n];
}



int main()
{
   int coins[]={1,2,3}; //each value is infinite supply
   int no_of_coins_types=3;
   int value=5;
   cout<<"Total ways to make the change : "<<count(coins,no_of_coins_types,value);

}
//ans is 5
