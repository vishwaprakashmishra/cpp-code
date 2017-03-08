#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int k, sum = 0;
    cin>>k;
    for ( int i = 0 ;i < n ;i++)
    {
        cin>>k;
        sum +=k;
    }
    cout<<sum;
    return 0;
}