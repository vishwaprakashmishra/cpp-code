#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, loaf = 0;
    cin>>N;
    vector<int> B(N);
    for ( int i =0 ;  i < N ;i++ ){
        cin>>B[i];
    }
    for( int i = 0 ;i < n-1; i++ )
    {
        if( B[i]%2== 1){
            B[i]++;
            B[i+1]++;
            loaf +=2;
        }
    }
    if( B[n-1]%2 == 1)
        cout<<"NO";
    else cout<<loaf;
    return 0;
    
}