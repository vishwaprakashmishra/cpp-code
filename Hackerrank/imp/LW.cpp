#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n , k , t , remainder, g, special=0;
    cin>>n>>k;
    vector<int> inputs(n);
    for( int i = 0 ;i < n ; i++ ){
        cin>>inputs[i];
    }
    
    vector<vector<int> > m; // in this every vector<int> is a page
    
    
    for( int i = 0 ; i < n; i++ ){ //looping all nodes
        g = inputs[i]/k;
        remainder = inputs[i]%k;
        vector<int> c(remainder);
        for( int j = 0 ; j < g; j++ ){ // looping all g;
            vector<int> v(k);       //page of book
            for(int l = 0 ; l < k ; l++ ){ //looping all question in g
                v[l] = (l+j*k)+1;
            }
            m.push_back(v);
        }
        for( int l = 0 ;l < remainder ; l++ ){
            c[l] = g*k+(l+1);
        }
        if( remainder > 0)
            m.push_back(c);
    }
    for( int i = 0 ; i < m.size() ; i++ ){
        for( int j = 0; j < m[i].size()  ; j++ ){
            if( m[i][j] == i+1)
                special++;
        }
    }
    cout<<special;
    return 0;
}