#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n,d, beautiful_triplet = 0;
    cin>>n>>d;
    vector<int> a(n);
    for( int i = 0 ; i < n ; i++ )
        cin>>a[i];
    for( int i = 0 ;i < n-2; i++ )
    {
        bool found_aj = false , found_ak = false ;
        int ak,aj;
        ak = a[i] +2*d;
        aj= a[i] + d;
        for( int j = i ;j < n ;i++ ){
            if( a[j] == aj ){
                found_aj= true;
            }
            if( a[j] == ak)
                found_ak= true;
                
        }
        if( found_aj == true && found_ak == true){
            beautiful_triplet++;
        }
    }
    cout<<beautiful_triplet;
    return 0;
}