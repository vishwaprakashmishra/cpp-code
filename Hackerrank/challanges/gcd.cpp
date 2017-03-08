#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int gcd (long long int a, long long int b){
    if(b == 0)
        return a;
    else return gcd ( b , a%b );
}
int main() {
    int n, t;
    
    long long int ans;
    cin>>t;
    for (int m =1;m<=t;m++)
    {
        cin>>n;
        vector<long long int> in(n);        
        for(int i=0;i<n;i++){
            cin>>in[i];
        }
        if(n>=2){
            ans = gcd(in[0],in[1]);
            for(int i=2;i<n;i++){
                ans = gcd(ans, in[i]);
            }
            cout<<"Case "<<m<<": "<<ans<<endl;
            }
        else {
                cout<<"Case "<<m<<": "<<in[0]<<endl;
        }
    
    }
    return 0;
}
