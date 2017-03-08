#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n , k, bi;
    long long int su = 0 ;
    cin>>n >> k;
    vector<int> c(n);
    for( int i = 0 ; i < n ;i++ ){
        cin>>c[i];
        if( i != k) 
            su = c[i] + su;
        
    }
    su = su/2;
    cin>>bi;
    if( su == bi){
        cout<<"Bon Appetit";
    }
    else {
        cout<<bi - su<<endl;
    }
    return 0;
}