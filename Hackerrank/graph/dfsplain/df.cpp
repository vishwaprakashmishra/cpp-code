#include<bits/stdc++.h>
using namespace std;
struct graph{
  int n,m;
  vector<vector<int> > g;
  vector<int > par;
  vector<bool> vi;
  void inpg(){
      int x, y;
      cin>>n>>m;
      for( int i=0;i<n;i++){
          cin>>x>>y;
          g[x].push_back(y);
          g[y].push_back(x);
          
      }
      par = vector<int> (n+1);
      vi = vector<bool> (n+1);
      fill_n(par.begin(), n+1, -1);
      fill_n(vi.begin(), n+1, false);
  }  
  void dfs(int s){
      vi[s] =true;
      for( auto ed:g[s]){
          if( !vi[ed]){
              par[ed] = v;
              dfs(ed);
          }
      }
  }
};
int main(void )
{
    int t, s;
    cin>>t;
    while(t--){
        graph g;
        g.inpg();
        cin>>s;
        g.dfs(s);
        cout<<endl;
    }
    return 0;
}