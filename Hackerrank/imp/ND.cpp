#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n, k;
    cin>>n;
    vector<int> v(n);
    set<int> sub_set;
    for( int i= 0 ;i< n ;i++ ){
        cin>>v[i];
    }
    for( int i = 0 ; i < n ;i++ ){
        auto it = sub_set(k-v[i]);
        if( it != sub_set.end()){
            sub_set.insert(v[i]);
            continue;
        }
    }
    cout<<sub_set.size();
    return 0;
}