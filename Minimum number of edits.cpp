#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//given two strings s1,s2 and below operations that can be performed on
//s1. Find minimum number of edits(operations) required to convert 's1' into 's2'
//a>INSERT b>REMOVE c>REPLACE

//Naive recursive solution
int editDist(string s1,string s2,int n1,int n2)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if(n1==0)
        return n2;

    // If second string is empty, the only option is to
    // remove all characters of first string
    if(n2==0)
        return n1;

    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if(s1[n1-1]==s2[n2-1])
        return editDist(s1,s2,n1-1,n2-1);

    // If last characters are not same, consider all three
    // operations on last character of first string, recursively
    // compute minimum cost for all three operations and take
    // minimum of three values.
    return 1+min(editDist(s1,s2,n1,n2-1),         //Insert
                 min(editDist(s1,s2,n1-1,n2),     //Remove
                     editDist(s1,s2,n1-1,n2-1))); //Replace

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
