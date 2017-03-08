#include<bits/stdc++.h>
using namespace std;

int main(void){
    double x, y,a,b;
    cin>>x>>y;
    cin>>a>>b;
    double k,n;
    k = (x*a+y*b)/(a*a + b*b);
    cout<<fixed<<setprecision(12)<<k<<endl;
    n = (y-k*b)/(a);
    cout<<fixed<<setprecision(12)<<n<<endl;
    return 0;
}