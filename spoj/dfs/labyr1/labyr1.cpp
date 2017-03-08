#include<bits/stdc++.h>
using namespace std;
struct graph{
    int n,m;
    vector<string> g;
    vector<vector<bool> > vi;
    vector<vector<int> > di;
    void inpg(){
        cin>>m>>n;
        g = vector<string> (n);
        for( int i=0;i<n;i++)
            cin>>g[i];
        
        vi  = vector<vector<bool> > (n, vector<bool> (m));
        for( int i=0;i<n;i++) fill_n(vi[i].begin(), m, false);
        di = vector<vector<int> > (n, vector<int> (m));
        for( int i=0;i<n;i++) fill_n(di[i].begin(), m , 0);
    }
    void edges(vector<pair<int,int> > &eds, pair<int,int> ed){
        eds = vector<pair<int, int> > ();
        if(ed.first-1>=0 && g[ed.first-1][ed.second] == '.')
        eds.push_back(make_pair(ed.first-1, ed.second));
        if( ed.first+1<n && g[ed.first+1][ed.second] =='.')
        eds.push_back(make_pair(ed.first+1, ed.second));
        if( ed.second-1>=0 && g[ed.first][ed.second-1]=='.')
        eds.push_back(make_pair(ed.first, ed.second-1));
        if( ed.second+1 <n && g[ed.first][ed.second+1]=='.')
        eds.push_back(make_pair(ed.first, ed.second+1));
    }
    void dfs(pair<int, int> s){
        vi[s.first][s.second] = true;
        vector<pair<int,int> > eds;
        edges(eds, s);
        for( auto ed: eds){
            if( !vi[ed.first][ed.second]){
                di[ed.first][ed.second] = di[s.first][s.second]+1;
                dfs(ed);
            }
        }
    }
    void sol(){
        bool flag = false;
        pair<int, int> s, one_end;
        for( int i=0;i<n;i++){
            for( int j=0;j<m;j++){
                if( g[i][j] =='.'){
                    s  = make_pair(i,j);
                    flag = true;
                    break;
                }
            }
            if(flag )
            break;
        }
        dfs(s);
        
        int maxi=0;
        one_end.first = -1;
        one_end.second= -1;
        
        for( int i=0;i<n;i++){
            for( int j=0;j<m;j++){
                if( maxi < di[i][j]){
                    maxi = di[i][j];
                    one_end.first = i;
                    one_end.second = j;
                }
            }
        }
        if( one_end.first ==-1) cout<<"Maximum rope length is 0."<<endl;
        else { 
            for( int i=0;i<n;i++) fill_n(vi[i].begin(), m, false);
            for( int i=0;i<n;i++) fill_n(di[i].begin(), m, 0);
            dfs(one_end);
            for( int i =0;i<n;i++){
                for( int j=0;j<m;++j){
                    if( maxi < di[i][j]){
                        maxi = di[i][j];
                    }
                }
            }
            cout<<"Maximum rope length is "<<maxi<<"."<<endl;
        }
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