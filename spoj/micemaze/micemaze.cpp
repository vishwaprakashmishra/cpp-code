#include<bits/stdc++.h>
using namespace std;
class Compare
{
    public:
    bool operator() (pair<int,int> p1,pair<int,int> p2){
        return p1.second > p2.second;
    }
};
struct graph{
    vector<vector<pair<int,int> > > g;
    vector<bool> vi;
    vector<int > di;
    int n,s,t,m;
    void inpg(){
        int x, y, w;
        cin>>n>>s>>t>>m;
        g = vector<vector<pair<int,int> > > (n+1,vector<pair<int,int> > ());
        vi = vector<bool> (n+1);
        di = vector<int> (n+1);
        fill_n(vi.begin(),n+1, false);
        fill_n(di.begin(),n+1,INT_MAX);
        for( int i=0;i<m;i++){
            cin>>x>>y>>w;
            g[y].push_back(make_pair(x,w));
        }
    }
    void dij(int s){
        int v = s;
        di[s]=0;
        priority_queue<pair<int,int> , vector<pair<int,int> > , Compare > pq;
        pq.push(make_pair(s, 0));
        while ( !pq.empty()){
            v = pq.top().first;
            pq.pop();
            for( auto ed:g[v]){
                if( di[ed.first] > di[v]+ ed.second){
                    di[ed.first] = di[v]+ed.second;
                    pq.push(make_pair(ed.first,di[ed.first]));
                }
            }
        }
        int mice =0;
        for(int i=0;i<=n;i++){
            if( di[i] <= t ) mice++;
        }
        cout<<mice;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    graph g;
    g.inpg();
    g.dij(g.s);
    return 0;
}