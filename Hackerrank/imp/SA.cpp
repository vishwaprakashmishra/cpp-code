#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n, k=5,ans=0 ;
    cin>>n;
    for( int i=1;i<=n;i++){
        ans = ans + k/2;
        k = k/2;
        k = k*3;
    }
    cout<<ans<<endl;
    return 0;
}