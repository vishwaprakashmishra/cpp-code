#include<bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n )
{   
    // Create a boolean vector "prime(n+1) " and initialize
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is not a prime, else true 
    vector<bool> prime(n+1);
    fill_n(prime, 0, n+1);
    
    for( int p= 2 ;  p*p <= n ;p++ ){
        // If prime[p] is not changed, then it is a prime
        if(prime[p] == true){
            // Update all multimples of p 
            for( int i = p*2; i <=n;i +=p )
                prime[i] = false;
        }
    }
    // Print all prime numbers 
    for( int p = 2 ;  p <= n; p++ )
        if( prime[p])
            cout<< p << " " ;
}

int main(void){
    int n = 30 ; 
    cout<< " Following are the prime number smaller " 
    << "than or equal to " << n <<endl;
    SieveOfEratosthenes(n);
    return 0;
}