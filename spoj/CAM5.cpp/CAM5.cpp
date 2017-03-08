#include<bits/stdc++.h>
using namespace std;
struct graph{
    int n, m;
    vector<vector<int> > g;
    vector<bool> vi;
    
    void inpg(){
        int x, y;
        cin>>n>>m;
        g  =vector<vector<int> > (n, vector<int> ());
        for( int i=0;i<m;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
            
        }
        vi = vector<bool> (n);
        
    }  
    void dfs(int s){
        vi[s] = true;
        for( auto ed: g[s]){
            if( vi[ed] ==false ){
                dfs(ed);
            }
        }
    }
    void sol(){
        int count = 0;
        for( int i=0;i<n;i++){
            if( vi[i] ==false )
            {
                dfs(i);
                count++;
            }
        }
        cout<<count<<endl;
    }
};
int main(void){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    
    while ( t--){
        graph g;
        g.inpg();
        g.sol();
    }
    return 0;
}