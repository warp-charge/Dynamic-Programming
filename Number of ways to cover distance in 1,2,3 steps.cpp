#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//Given a distance dist, count total number of ways to cover the distance with 1, 2 and 3 steps.
//recursive solution
//a distance with 1,2,and 3 steps
//time complexity is close to O(3^n)
/*int countDist(int dist)
{
    if(dist<0)
        return 0;
    if(dist==0)
        return 1;

    return countDist(dist-1)+countDist(dist-2)+countDist(dist-3);
}*/

//DP Bottom Up Approach
int countDist(int dist)
{
    int cnt[dist+1],i;
    cnt[0]=1; cnt[1]=1; cnt[2]=2;
    for(i=3;i<=dist;i++)
    {
        cnt[i]=cnt[i-1]+cnt[i-2]+cnt[i-3];
    }
    return cnt[dist];
}

int main()
{
    int dist=4;
    cout<<countDist(dist)<<"\n";
}
