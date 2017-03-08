#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int t , ans;
    int n;
    cin>>t ;
    n = log2(t/(3.0)+1);
    ans = t - 3*(pow(2,n) -1);
    ans = 3*(pow(2,n))+1 - ans;
    cout<<ans;
    return 0;
}