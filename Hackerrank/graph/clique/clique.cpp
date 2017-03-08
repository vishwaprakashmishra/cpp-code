#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t , n , m, sol ;
    
    cin>>t;
    while(t--){
        cin>>n>>m;
        sol = floor(n*n/(n*n-2*m));
        if( m <= ((sol-1)*n*n)/(2*1.0*sol))
            cout<<sol<<endl;
        else {
            while( m > ((sol-1)*n*n)/(2*1.0*sol) )
             sol++;    // what we are trying to get
            cout<<sol<<endl; // is value of k which is sufficiently
        }// large enough to cover the equation
    }   
}