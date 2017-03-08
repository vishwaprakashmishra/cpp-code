#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n ;
    long long int sum = 0;
    cin>>n;
    vector<int> v(n);
    for ( int i = 0 ; i < n ; i++ )
    {
        cin>>v[i];
    }   
    vector<int> s(n);
    fill_n(s.begin(),n, 1);
    for ( int i = 1 ;i < n ; i++ )
    {
        
        if( v[i] > v[i-1]){
            s[i] = s[i-1]+1;
        }
    }
    for( int i = n-2 ; i >=0 ; i-- ){
        if( v[i] > v[i+1])
        {
            if( s[i] <= s[i+1]+1)
            s[i] = s[i+1]+1;
        }
    }
    for( int i = 0 ;i< n ;i++ )
    sum = sum + s[i];
    cout<<sum;
    return 0;
}