#include<bits/stdc++.h>
using namespace std;
struct graph {
    int n,m;
    vector<vector<int> > graph;
    vector<bool> vi;
    vector<int> di;
    void inpg(){
        int x,y;
        cin>>n>>m;
        g = vector<vector<int> > (n+1,vector<int> ());
        for( int i=0;i<m;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        vi = vector<bool> (n+1);
        di = vector<int> (n+1);
        fill_n(vi.begin(), n+1, false );
        fill_n(di.begin() , n+1, INT_MAX);
    }  
    void bfs(int s){
        vi[s]=true;
        di[s]=0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for( auto ed:g[v]){
                if( !vi[ed]){
                    q.push(ed);
                    vi[ed]  = true;
                    di[ed] = di[v]+6;
                }
            }
        }
        for( int i=1;i<=n;i++){
            if( di[i] ==0) continue;
            else if( di[i]==INT_MAX) cout<<"-1 ";
            else cout<<w<<" " ;
        }
        cout<<endl;
    }
};
int main(void){
    ios_base::sync_with_stdio(false);
    int q,s;
    cin>>q;
    while( q--){
        graph g;
        g.inpg();
        cin>>s;
        g.bfs(s);
    }
    return 0;
}