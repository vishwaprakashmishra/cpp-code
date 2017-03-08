#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, k, q,x;
    cin>>n>>k>>q;
    vector<int> v(n);
    for( int i = 0 ;i < n;i++ )
    {
        cin>>v[i];
    }
    k = k%n;
    for ( int i = 0 ; i < q ; i++ )
    {
        cin>>x;
        if( x < k)
            x = x + (n-k);
        else
            x = x-k;
        cout<<v[x]<<endl;
    }
    return 0;
}