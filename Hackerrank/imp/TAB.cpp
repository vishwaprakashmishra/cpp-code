#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t, W, B, X, Y , Z;
    cin>>t ;
    for( int i = 0 ;i < t ; i++ ){
        cin>>B>>W;
        cin>>X>>Y>>Z;
        
        if( X+Z < Y){
            cout<<X*B+ ( X+Z)*Y<<endl;
        }else if( Y+Z < X ){
            cout<<(Y+Z)*B + Y*W<<endl;
        }else {
            cout<<X*B+Y*W<<endl
        }
    }
    return 0;
}