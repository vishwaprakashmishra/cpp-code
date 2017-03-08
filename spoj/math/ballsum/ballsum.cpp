#include<bits/stdc++.h>
using namespace std;

long long int gcd (long long int a , long long int b )
{
    if( b ==0) return a;
    else return gcd (b , a%b);
}

int main(void){
    ios_base::sync_with_stdio(false);
    long long int n  , k, sol, den, d;
    while(true){
        cin>>n>>k;
        if( n==-1 && k==-1) break;
        else if( k > 0 && n > 0){
            if( k%2 == 0){
                sol = (k*((k-4)/2+1))/2;
                den = (n*(n-1))/2;
                d = gcd (sol, den);
                
            }
            else {
                sol = ((k-1)*((k-3)/2 +1))/2;
                den = (n*(n-1))/2;
                d = gcd(sol, den);
            }
            sol = sol/d;
            den = den/d;
            if( sol == 0) cout<<sol<<endl;
            else 
            cout<<sol<<"/"<<den<<endl;
        }
        else {
            cout<<"0"<<endl;
        }
    }    
    return 0;
}