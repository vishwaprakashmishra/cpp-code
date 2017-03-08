#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    for( int i  = 0 ;i < n ;i++ ) cin>>a[i];
    vector<int> b(a);
    sort(b.begin(), b.end());
    vector<int> equals;
    for( int i = 0 ; i <= n-2 ;i++ )
    {
        if( b[i] == b[i+1])
            equals.push_back(b[i]);
    }
    
    if( equals.size() == 0) cout<<"-1";
    else {
        int counter = -1, k = 0;
        vector<int> store(equals.size());
        for( int i  = 0 ;i < equals.size() ; i++ ){
            counter = -1;
            for( int j = 0 ; j < n ; j++ ){
                if( a[j] == equals[i]){
                    if(counter == -1)
                        counter = j;
                    else store[k++] = j-counter;
                }
            }
        }
        sort(store.begin(),store.end());
        cout<<store[0];
    }
    return 0;
}