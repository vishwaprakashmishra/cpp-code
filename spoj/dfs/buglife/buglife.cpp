#include<bits/stdc++.h>
using namespace std;
struct graph {
    vector<vector<int> > g;
    int n, m;
    vector<int > col;
    vector<bool> vi;
    void inpg(){
        int x, y;
        cin>>n>>m;
        g = vector<vector<int> > (n+1, vector<int>());
        for( int i= 0; i<m;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        col = vector<int> (n+1);
        vi = vector<bool> (n+1);
        fill_n(vi.begin(), n+1, false);
        fill_n(col.begin(), n+1, -1);
    }
    bool bfs(int s ){
        queue<int> q;
        vi[s] = true;
        col[s ] = 1;
        q.push(s);
        bool discrepancy = false;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for( auto e:g[v]){
                if( !vi[e]){
                    vi[e] = true;
                    col[e] = !col[v];
                    q.push(e);
                }
                else if( col[e]==col[v]){
                    discrepancy  = true;
                    return discrepancy;
                }
            }
        }
        return discrepancy;
    }
    bool sol(){
        for( int i=n;i>=1;--i){
            if( !vi[i] ){
                col[i] = 1;
                if( bfs(i) == true ) return true;
            }
        }
        return false;
    }
};

int main(void){
    int t;
    cin>>t;
    int n= t;
    while (t--){
        graph g;
        g.inpg();
        if( g.sol()) cout<<"Scenario #"<<n-t<<":\nSuspicious bugs found!"<<endl;
        else cout<<"Scenario #"<<n-t<<":\nNo suspicious bugs found!"<<endl;

    }
    return 0;
}