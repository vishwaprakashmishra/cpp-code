#include<bits/stdc++.h>
using namespace std;

int count(vector<long long int> &s, vector<long long int> &table, int m , int n ){
    
    fill_n(table.begin(), n+1, 0);
    table[0] = 1 ; 
    
    for ( int i = 0 ; i < m  ; i++ )
        for( int j = s[i] ; j <= n ; j++ )
            table[j] += table[j-s[i]];
    return table[n];
}
int  main(void){
    int n, m;
    cin>>n>>m;
    vector<long long int> table(n+1);
    vector<long long int> s(m);
    for( int i = 0 ; i < m ; i++ )
        cin>> s[i];
    cout<<count(s,table,m,n)<<endl;
    return 0;
}