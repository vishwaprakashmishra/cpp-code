#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;

struct graph{
    int n,m;
    vector<vector<int> > g;
    vector<bool> vi;
    vector<int > par;
    
    void inpg(){
        cin>>n>>m;
        int x, y;
        g = vector<vector<int> > (n+1,vector<int> ());
        for( int i=0;i<m;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vi = vector<bool> (n+1);
        par = vector<int > (n+1);
    }
    int  dfs(int s){
        vi[s] = true;
        for( auto ed:g[s]){
            if( !vi[ed])
            {
                par[ed] = s;
                dfs(ed);
            }
            else if( par[s] != ed)
                return 0;
        }
        return 1;
    }
    void ans(){
        fill_n(vi.begin(), n+1, false);
        fill_n(par.begin(), n+1, -1);
        int re = dfs(1);
        if( re == 0)
        cout<<"NO"<<endl;
        else 
        cout<<"YES"<<endl;
    }
};

int main(void){
    graph g;
    g.inpg();
    g.ans();
    return 0;
    
}