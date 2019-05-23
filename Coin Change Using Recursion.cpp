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

int count(int coins[],int m,int n)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(m<=0 && n>=1)
        return 0;

        //i)excluding coins[m-1]  ii) including coins[m-1]
    return count(coins,m-1,n)+count(coins,m,n-coins[m-1]);
}


int main()
{
   int coins[]={1,2,3}; //each value is infinite supply
   int no_of_coins_types=3;
   int value=5;
   cout<<"Total ways to make the change : "<<count(coins,no_of_coins_types,value);

}
//ans is 5

