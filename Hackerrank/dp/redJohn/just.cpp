#include <bits/stdc++.h>

using namespace std;
int main(void)
{
    long long int sum = 1;
    int i,n;
    cin>>n;
    for( int i = 1 ;  i <= n ; i++ )
    {
        sum *= i;
    }
    cout<<sum<<endl;
    cout<<LLONG_MAX<<endl;
    return 0;
}