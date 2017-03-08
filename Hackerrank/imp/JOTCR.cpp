#include <bits/stdc++.h>
using namespace std;

int main(void){
    int d ,  n, k, e = 100;
    cin>>n>>k;
    vector<int> c(n);
    for( int i  = 0 ;i < n ;i++ )
    cin>>c[i];
    int i = 0;
    while( d !=0){
        d = (i+k)%n;
        i = d;
        if( c[d] == 1){
            e -=2;
        }
        e--;
    }
    cout<<e;
    return 0;
}