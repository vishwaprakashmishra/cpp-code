#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class an{
  public:
    vector<long long int> fact;
    long long int perm;
    int n  ,m ;
    void in(){
        cin>>n>>m;
        fact = vector<long long int>(min(n,m)+1);
        f();
        perm = 1;
    }
    void ans(){
        int i,diff = abs(m-n);
        if(diff >0){
            for( i=1;i<=min(m,n);i++) 
                perm = (fact[i]*perm)%1000000007;
            perm = (perm*perm)%1000000007;   
            diff--;
            i= min(n, m );
            while(diff >0){
                perm = (perm*fact[i])%1000000007;
                diff--;
            }
        }
        else if( diff ==0){
            for( i=1;i<min(m,n);i++) 
                perm = (fact[i]*perm)%1000000007;
            perm = (fact[i]*perm)%1000000007;
        }
        cout<<perm<<endl;
    }
    void f(){
        long long int ans=1;
        for( int i=1; i<=min(m,n);i++){
            ans = (ans*i)%1000000007;
            fact[i] = ans;
        }
    }
};

int main() {
    an a ;
    a.in();
    a.ans();
    return 0;
}
