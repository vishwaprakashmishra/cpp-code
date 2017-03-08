#include<iostream>
using namespace std;
int main(void){
    int t;
    cin>>t;
    while (t--){
        int n, m, sol =0;
        cin>>n>>m;
        if( n>=2 && m >=2){
            if( n%2==0 ||m%2==0){
                sol +=((n-2)*(m-2))*2;
                sol +=(m+n-4)*3 + 4;
            }
            else {
                int k = ((n-2)*(m-2))/2;
                k = k*4;
                sol = sol+k;
                sol = sol + ((n/2)+(m/2))*6;
            }
        }
        else if( n==1&& m==1) sol = 0;
        else {
            if( n%2==0 ||m%2==0){
                int k = max(n,m);
                sol = sol + ((k-1)/2)*2 +1;
                
            }   else {
                int k = max(n,m);
                sol = sol +(k/2)*2;
                
            }
        }
        cout<<sol<<endl;
    }
}