#include<bits/stdc++.h>
using namespace std;

class comparator{
    public:
        bool operator() ( int a, int b )
        {
            return a< b;
        }
};
struct graph{
    int n, m;
    vector<vector<pair<int, int> > > g;
    vector<bool > vi;
    vector<int > di;
    
    void inpg(){
        int x, y, w;
        cin>>n;
        g = vector<vector<pair<int, int > > > (n+1, vector<pair<int, int> > ());
        for( int i=0;i<n-1;i++)
        {
            cin>>x>>y>>w;
            g[x].push_back(make_pair(y,w));
            g[y].push_back(make_pair(x,w));
        }
        vi = vector<bool > (n+1);
        di = vector<int > (n+1);
    }  
    void dfs(pair<int, int> s){
        vi[s.first] = true;
        for( auto ed:g[s.first]){
            if( !vi[ed.first] ){
                di[ed.first] = di[s.first] + ed.second;
                dfs(ed);
            }
        }
    }
    void sol(){
        fill_n(vi.begin(), n+1, false);
        fill_n(di.begin(), n+1, 0);
        
        dfs(make_pair(1,0));
        int maxi = 0, pos = 0;
        for(int i =0;i<=n;++i){
            if( di[i] > maxi){
                maxi = di[i];
                pos = i;
            }
        }
        fill_n(di.begin(), n+1, 0);
        fill_n(vi.begin(), n+1, false);
        dfs(make_pair(pos, 0));
        maxi= 0,pos = 0;
        for( int i = 1;i<=n;i++){
            if( di[i] > maxi){
                maxi = di[i];
                pos = i;
            }
        }
        cout<<maxi<<endl;
    }
};

int main(void){
    int t ;
    cin>>t ;
    while (t--){
        graph g;
        g.inpg();
        g.sol();
    }
    return 0;
}