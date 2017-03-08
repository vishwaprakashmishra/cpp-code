#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int n,k;long long int sum =0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cin>>k;
    for( int i=0;i<k;i++)
        sum+=v[i];
    cout<<sum<<" " ;
    for( int i=k;i<n;i++){
        cout<<sum+v[i]-v[i-k]<<" " ;
    }
    return 0;
}
# the solution is quite wrong its quite a standard problem
# known as window sliding prolbems 
# you can find it on spoj also