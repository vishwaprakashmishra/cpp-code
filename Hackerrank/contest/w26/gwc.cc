#include<iostream>
using namespace std;
int main(void){
    int n , m ,k , l , ans =0;
    cin>>n>>m;
    if( n<=2 && m<=2) 
    {
        cout<<"1"<<endl;
        return 0;
    }
    k = n/2;
    l = m/2;
    ans += k*l;
    if( n%2==1 && m%2==1)
        ans += (k+l+1);
    else if( n%2==1)
        ans += l;
    else if( m%2 == 1)
        ans += m;
    cout<<ans<<endl;
    return 0;
}