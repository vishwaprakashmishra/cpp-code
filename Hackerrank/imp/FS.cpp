#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n , m, d_max, st = 0 , en;
    cin>>n>>m;
    vector<int> inp(m);
    for( int i = 0 ;i < m ; i++ ){
        cin>>inp[i];
    }
    sort(inp.begin(), inp.end());
    d_max = inp[0];
    st = 0 , en = inp[0] ;
    for( int i = 0 ;i < m-1 ; i++ ){
        if( inp[i+1] - inp[i] > d_max){
            d_max = inp[i+1] - inp[i];
            st= inp[i];
            en = inp[i+1];
        }
    }
    if( (!(st==0&&inp[st]==d_max))&& (!(st == inp[m-1] && d_max==n-inp[m-1] )) ){
        if( d_max%2 == 0)
            cout<< d_max/2;
        else cout<< d_max/2 + 1;
    }
    else {
        cout<<d_max;
    }
    return 0;
}