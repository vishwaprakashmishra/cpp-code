#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long int gcd (long long int a, long long int b){
    if( b == 0){
        return a;
    }
    return gcd(b, a%b);
}
long long int lcm(vector<long long int> &a, long long int n){
    long long int ans = a[0];
    if( n >=2){
    for( long long int i=1;i<n;i++)
        ans = ( a[i]*ans)/gcd(a[i], ans);
    }
    return ans;
}
int main(void){
    long long int t;
    cin>>t;
    while( t--){
        long long int n, k;
        cin>>n>>k;
        
        vector<long long int> a(n);
        for( long long int i=0;i<n;i++)   cin>>a[i];
        
        
        long long int ans = lcm(a, n);
        if( ans%k ==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}