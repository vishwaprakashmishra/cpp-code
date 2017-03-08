#include<bits/stdc++.h>
using namespace std;
struct graph{
    vector<vector<char> > g;
    int n,m;
    //inputgraph 
    void inpg(){
        cin>>n>>m;
        g = vector<vector<char> > (n,vector<char> (m)); 
        for( int i= 0;i<n;i++){
            for(int j=0;j<m;j++)
            cin>>g[i][j];
        }
    }
    //addiing up the edges
    void edges(pair<int,int> e, vector<pair<int,int> > &r){
        r = vector<pair<int,int> >();
        vector<pair<int,int> > r;
        if( e.first-1>=0 && g[e.first-1][e.second]=='.')
        r.push_back(make_pair(e.first-1,e.second));
        if( e.first+1<n &&g[e.first+1][e.second] =='.')
        r.push_back(make_pair(e.first+1,e.second));
        if( e.second-1>=0 &&g[e.first][e.second-1]=='.')
        r.push_back(make_pair(e.first][e.second-1]));
        if(e.second+1 <m && g[e.first][e.second+1]=='.')
        r.push_back(make_pair(e.first,e.second+1));
    }
    //our badass mother Bfs
    bool sameLine(pair<int,int> ed,pair<int,int> e)\
    {
        if()
    }
    int Bfs(pair<int,int> s){
        vector<vector<pair<int,int> > > par( n, vector<pair<int,int> > (m));
        for( int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                par[i][j] = make_pair(-1,-1);
            }
        }
        queue<pair<int.int> > q;
        q.push(s);
        vector<vector<bool> > vi(n,vector<bool> (m));
        for( int i = 0 ;i<n;i++)
            fill_n(vi[i],m,false);
        while(!q.empty()){
            e = q.front();
            q.pop();
            vector<pair> > eds(0);
            edges(e,eds);
            for( auto ed:eds){
                if(vi[ed.first][ed.second] ==false){
                    vi[ed.first][ed.second] = true;
                    q.push(ed);
                    par[ed.first][ed.second] = e; 
                }
            }
        }
        pair<int,int> c;
        c = make_pair()
    }
}
int main(void){
    
    return 0;
}