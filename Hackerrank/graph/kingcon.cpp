#include<bits/stdc++.h>
using namespace std;
#define white   0
#define grey    1
#define black   2
#define long long int LL
class graph {
    vector<vector<int> >  g, reverse_edges, edges;
    vector<int> vi;
    vector<bool> cycle_reachable_from_src;
    void in(){
    }
    void dfs(int node , vector<bool>& cycle){
        vi [node]  = grey;
        for(auto e:g[node]){
            if( vi[e] == white)
                dfs(e, cycle);
            else if(vi[e] == grey)
                cycle[e] = true;// this is cycle point 
        }
        vi[node] =black;
    }
    void dfs(int node ){
        vi[node] =grey;
        for(auto e: g[node])
            if(vi[e] == white)
                dfs(e);
        vi[node]  = black;
    }
    bool check_cycle(){
        dfs(src , cycle_reachable_from_src);
        fill_n(vi.begin(), n+1, 0);
        dfs(dest, reverse_edges);
        for(int i =0;i<=n;i++)
            if(cycle_reachable_from_src[i] && vi[i] = black)
                return true;
        return false;
    }
    LL call (int node){
        if( cycle_reachable_from_src[node] == true)
            return 0;
        if( node == dest )
            return 1;
        if( d[node] != -1)
            return dp[node];
            
        LL ret =0;
        for( auto e :edges[node]){
            ret = (ret+call(e))%MOD;
        return dp[node] = ret;
    }
};
int main(void){
    return 0;
}