#include<bits/stdc++.h>
using namspace std;
int n,m,k;
class comp{
    public:
    bool operator() (pair<int,int> lt, pair< int, int> rt){
        return lt.second < rt.second;      
    }
};
struct graph{
    int n, m;
    vector<vector<pair<int, int> > > g;
    vector<vector<int>  >fish;
    vector<int> di;
    
    void inpg(int n, int m){
        this->n = n;
        this->m = m;
        fish = vector<vector<int> > (n+1, vector<int> ());
        g = vector<vector<int> > ( n+1, vector<int> ());
        for( int i=1;i<=n;i++){
            int sz,fish_type;
            cin>>sz;
            for(int j=0;j<sz;++j){
                cin>>fish_type;
                fish[i].push_back(fish_type);
            }
        }
        int x, y, w;
        for( int i=0;i<m;i++){
            cin>>x>>y>>w;
            g[x].push_back(make_pair(y,w));
            g[y].push_back(make_pair(x,w));
        }
    }
    void dij(int s){
        
    }
};
int main(void)
{
    cin>>n>>m>>k;
    for(int i= 0 ;i<n;i++) {
        cin>>t;
        graph g;
        g.inpg( n, m);
        g.sol();
    }
}