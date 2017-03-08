#include<bits/stdc++.h>
using namespace std;

int main(void){
    int t ;
    cin>>t;
    while(t--){
        int a , b ,c ;
        cin>>a>>b>>c;
        if( c > a && c > b )
            cout<<"-1"<<endl;
        else {
            int diff = abs(a-b);
            float k1 = (max(a, b) -c)/(1.0*diff);
            float k2 = c/diff;
            if( floor(k1) == k1) cout<<no of steps
            else if( floor(k2) == k2) cout<<no of steps
        }
    }
    
    return 0;
}