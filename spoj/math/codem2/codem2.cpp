#include<bits/stdc++.h>
using namespace std;
int main(void){
    int t, x, y ,n , ansi;
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        if( n == 0){ 
            cout<<"impossible"<<endl;
            break;
        }
        float ans = pow((pow(x, n) + pow(y, n)), 1.0/n);
        ansi = floor(ans);
        if( ansi == ans) cout<<ans<<endl;
        else cout<<"impossible"<<endl;
    }
    return 0;
}