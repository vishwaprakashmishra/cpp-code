#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    long long int sum = 0, k;
    cin>>n;
    for ( int i = 0 ; i <n ; i++ )
    {
        cin>>k;
        sum += k;
    }
    cout << sum ;
    return 0;
}