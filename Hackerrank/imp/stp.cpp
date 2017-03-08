#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t, n , m  , s ;
    int r ;
    cin>>t;
    for( int i = 0 ;i < t ; i++ ){
        cin>>n>>m>>s;
        r  = m%n;
        if( r== 0 && s== 1) cout<<n<<endl;
        else if( s+r-1 <=n ){
            cout<< s+(r-1)<<endl;
        }
        else {
            cout<<s+(r-1)-n<<endl;
        }
    }
    return 0;
}