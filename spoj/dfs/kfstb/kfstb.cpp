#include<iostream>
#include<vector>
using namespace std;
#define ll long long int 
class graph {
  public:
    int src, dest, n , m ;
    vector<vector<int> > g;
    vector<ll> dp;
    
    void in(){
        ios_base::sync_with_stdio(false);
        int x, y ; 
        cin>>n>>m>>src>>dest; 
        g = vector<vector<int> > (n+1 , vector<int> ());
        for( int i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back(y);
        }
        dp = vector<ll> (n+1);
        fill_n(dp.begin(), n+1, -1);
    }
    ll call(int node){
        if (node == dest)
            return 1;
        if( dp[node] != -1) 
            return dp[node];
        ll ret = 0;
        for( auto e:g[node])
            ret = (ret +call(e))%1000000007;
        return dp[node] = ret;
    }
};
int main(void){
    ios_base::sync_with_stdio(false);
    int t ;
    cin>>t;
    while(t--){
        graph g;
        g.in();
        cout<<g.call(g.src)<<endl;
    }
    return 0;
}