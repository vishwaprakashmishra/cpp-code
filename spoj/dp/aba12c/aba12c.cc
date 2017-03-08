#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class mi{
    public:
        int packet ;
        vector<int> p, c;
        int n , k ;
        void in(){
            cin>>n >>k;
            p = vector<int> (k+1);
            c = vector<int> (k+1);
            for( int i=1;i<=k;i++)
                cin>>p[i];
        }
        int min(int n ){
            if( n ==0) 
                return 0;
            if( n >0) packet++;
            if( packet > n) return -1;
            
            if( c[n] >=0)
                return c[n];
            
            c[n] = INT_MAX;
            for( int i=1;i<=n;i++){
                int temp ,  q ;
                temp =  min(n-i);
                if( temp < 0) continue;
                if( p[i]< 0) continue ;
                
                q = p[i] + temp;
                if( q < c[n]){
                   c[n] = q;
                }
            }
            packet--;
            if( c[n] == INT_MAX) return -1;
            else return c[n];
        }
        void sol(){
            fill_n(c.begin(), k+1, -1);
            packet =0;
            cout<<min(k)<<endl;
        }
};
int main(void){
    int t ;
    cin>>t;
    while(t--){
        mi m ;
        m.in();
        m.sol();
        
    }
    return 0;
    
}