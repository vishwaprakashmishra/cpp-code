#include<bits/stdc++.h>
using namespace std;

class comp{
    public:
    bool operator() (pair<int, int> p1, pair< int, int> p2){
        return p1.second<p2.second;
    }
};
struct graph {
    int n;          //inputable
    string source, dest;  //counter inputable
    map<string, int> node ;//inputable
    vector<vector<int> > g;//inputable
    vector<bool > vi;   //visited for runtime analysis of node
    vector<int> di; // distance for runtime analysis of node 
    vector<int > par ;
    vector<pair<string, string> > queries;//inputable
    void inpg(){
        int y, w;
        cin>>n;
        g = vector<vector<int> > (n+1, vector<int> ());
        for( int i =1;i<=n;++i){
            string no;
            cin>>no;
            node[no] = i;
            int k;
            cin>>k;
            for( int i =0;i<k;++i){
                cin>>y>>w;
                g[i].push_back(make_pair(y,w));
            }
        }
        int q;
        cin>>q;
        queries = vector<pair<string, string> > (q);
        for( int i=0;i<q;i++){
            cin>>source>>dest;
            queries.push_back(make_pair(source, dest));   
        }
        par = vector<int> (n+1);
        vi = vector<bool> (n+1);
        di = vector<int> (n+1);
        
    }
    void dij(int s){
        fill_n(vi.begin(), n+1, false);
        fill_n ( di.begin(), n+1,INT_MAX);
        fill_n( par.begin(), n+1, -1);
        vi[s] = true;
        di[s] = 0;
        
        priority_queue<pair<int, int> , vector< pair<int, int> > , comp> pq;
        pq.push(make_pair(s, 0));
        while( !pq.empty()){
            pair<int, int> v = pq.top();
            pq.pop();
            for( auto ed:g[v.first]){
                if(di[ed.first ] > di[v.first]+v.second){
                    di[ed.first] = di[v.first] + v.second;
                    par[ed.first] = v.first;
                    pq.push(ed);
                }
            }
        }
    }
    void sol(){
        int s, d;
        for( auto s_d:queries){
            s = node[s_d.first];
            d = node[s_d.second];
            dij(s);
            cout<<di[d]<<endl;
        }
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    int t;
    while(t--){
        graph g;
        g.inpg();
        g.sol();
    }
    return 0;
}