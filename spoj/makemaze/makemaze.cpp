#include<bits/stdc++.h>
using namespace std;
struct graph{
    vector<string> g;
    int m, n;
    vector<vector<bool> > vi;
    void inpg(){
        cin>>n>>m;
        g = vector<string> (n);
        for( int i=0;i<n;i++) cin>>g[i];
    }
    void edges(pair<int,int> e, vector<pair<int,int> > &eds){
        eds = vector<pair<int, int> > ();
        if( e.first-1>=0 && g[e.first-1][e.second] !='#')
        eds.push_back(make_pair(e.first-1,e.second));
        if( e.first+1<n && g[e.first+1][e.second] !='#')
        eds.push_back(make_pair(e.first+1, e.second));
        if( e.second-1 >=0 && g[e.first][e.second-1] !='#')
        eds.push_back(make_pair(e.first,e.second-1));
        if( e.second+1 < m && g[e.first][e.second+1] != '#')
        eds.push_back(make_pair(e.first, e.second+1));
    }
    void dfs( pair<int,int> s){
        vi[s.first][s.second]=true;
        vector<pair<int,int> > eds;
        edges(s,eds);
        for( auto ed:eds){
            if( !vi[ed.first][ed.second] )
            {
                dfs(ed);
            }
        }
    }
    void sol(){
        vi = vector<vector<bool> > (n, vector<bool> (m));
        for( int i=0;i<n;i++) fill_n(vi[i].begin(),m,false);
        set<pair<int,int> > starts;
        for( int i = 0 ;i< n;i++){
            if( g[i][0] == '.') starts.insert(make_pair(i,0));
            if( g[i][m-1] == '.') starts.insert(make_pair(i,m-1));
            
        }
        for( int i=0;i< m;i++){
            if( g[0][i] =='.') starts.insert(make_pair(0,i));
            if( g[n-1][i] =='.') starts.insert(make_pair(n-1,i));
        }
        if ( starts.size() == 2){
            set<pair<int,int> >::iterator p ;
            p = starts.begin();
            dfs(*p);
            p++;
            if( vi[p->first][p->second] ) 
            cout<<"valid"<<endl;
            else 
            cout<<"invalid"<<endl;
        }
        else cout<<"invalid"<<endl;
    }
};
int main(void){
    int t;
    cin>>t;
    while(t--){
        graph g;
        g.inpg();
        g.sol();
    }
    return 0;
}