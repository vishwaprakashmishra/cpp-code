#include<bits/stdc++.h>
using namespace std;
struct graph{
    int n, m;
    vector<vector<int> > g;
    vector<bool> vi ;
    vector<int> di;
    
    void inpg(){
        int x, y;
        cin>>n;
        g = vector<vector<int> > (n+1, vector<int> ());
        
        for( int i=0;i<n-1;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        di = vector<int> (n+1);
        vi = vector<bool> (n+1);
        fill_n(vi.begin(), n+1, false);
        fill_n(di.begin(), n+1, 0);
        
    }
    void dfs(int s){
        vi[s] = true;
        for( auto ed:g[s]){
            if( !vi[ed] ){
                di[ed] = di[s]+1;
                dfs(ed);
            }
        }
    }
    void sol(){
        dfs(1);
        int c =0,point = 0;
        for( int i=1;i<=n;i++){
            if( di[i]> c){
                point = i;
                c = di[i];
            }
        }
        fill_n(vi.begin(), n+1, false);
        fill_n(di.begin(), n+1, 0);
        dfs(point);
        c = 0, point = 0;
        for( int i=1;i<=n;i++){
            if( c < di[i])
            {
                point = i;
                c = di[i];
            }
        }
        cout<<c<<endl;
    }
};

int main(void ){
    graph g;
    g.inpg();
    g.sol();
    return 0;
    
}