#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int gcd(int a , int b){
    if( b == 0) return a;
    else 
    return gcd (b , a%b);
}

int main(void){
    int i,n , m , lcm;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(i=0;i<n;i++) cin>>a[i];
    for( i=0;i<m;i++) cin>>b[i];
    vector<int > multiples, sols;
    multiples = vector<int> ();
    sols = vector<int > ();
    
    
    if( n>=2&& m>=2){
        
        
        lcm = a[0];
        for(int i=1;i<n;++i)
            lcm = (a[i]*lcm)/gcd(a[i],lcm);
        
        sort(b.begin(), b.end());
        
        int i =1;
        while(b[0] >= lcm*i){
            multiples.push_back(lcm*i);
            i++;
        }
        
        for(auto el:multiples){
            for( i=0;i<m;i++){
                
                if( b[i]%el != 0)
                    break ;
            }
            if(i==m) sols.push_back(m);
        }
        cout<<sols.size();
        
    }
    return 0;
}