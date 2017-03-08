#include<bits/stdc++.h>
using namespace std;
struct graph{
    vector<string> g;
    vector<vector<bool> > vi;
    int m, n;
    void inpg(){
        cin>>n>>m;
        g = vector<string> (n);
        for( int i=0;i<n;i++) cin>>g[i];
    }
    void edges(pair<int,int> e,vector<pair<int,int> > &eds){
        eds = vector<pair<int,int> > ();
        if( e.first-1 >=0 && g[e.first-1][e.second] !='#' )
        eds.push_back(make_pair(e.first-1,e.second));
        if( e.first+1<n && g[e.first+1][e.second] !='#')
        eds.push_back(make_pair(e.first+1,e.second));
        if( e.second-1>=0 && g[e.first][e.second-1] !='#')
        eds.push_back(make_pair(e.first,e.second-1));
        if( e.second+1< m && g[e.first][e.second+1] !='#')
        eds.push_back(make_pair(e.first,e.second+1));
    }  
    char bfs(pair<int,int> s){
        int wolf=0, sheep=0;
        vi[s.first][s.second]=true;
        queue<pair<int,int> > q;
        q.push(s);
        vector<pair<int,int> > eds;
        while(!q.empty()){
            pair<int,int> v;
            v = q.front();
            q.pop();
            vi[v.first][v.second]=true;
            edges(v,eds);
            if( g[v.first][v.second]=='k')
            sheep++;
            else if( g[v.first][v.second]=='v')
            wolf++;
            for( auto ed:eds){
                if( !vi[ed.first][ed.second])
                    q.push(ed);
                    vi[ed.first][ed.second]=true;
            }
        }
        if( wolf >=sheep)
            return wolf;
        else 
        return (-sheep);
    }
    void conn(){
        int i,j, wolf=0, sheep=0, bfs_ret;
        vi = vector<vector<bool> > (n,vector<bool> (m));
        for( i=0;i<n;i++) fill_n(vi[i].begin(), m,false);
        for( i=0;i<n;i++){
            for(j=0;j<m;j++){
                if( vi[i][j] == false && g[i][j] !='#'){
                    pair<int,int> p;
                    p = make_pair( i,j);
                    bfs_ret = bfs(p);
                    if( bfs_ret>0)
                    wolf+=bfs_ret;
                    else   sheep -= bfs_ret;
                }
            }
        }
        cout<<sheep<<" "<<wolf;
    }
};
int main(void){
    graph g;
    g.inpg();
    g.conn();
    return 0;
}