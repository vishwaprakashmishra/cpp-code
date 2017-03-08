#include<bits/stdc++.h>
using namespace std;

struct graph {
    int n, m, Nsolder;
    vector<vector<int> > g;
    vector<bool> vi;
    vector<pair<int, int> > solders;
    vector<int > vi_sno;
    vector<int> di;
    void inpg(){
        int x, y;
        cin>>n>>m>>Nsolder;
        g = vector<vector<int> > (n+1, vector<int> ());
        for( int i=0;i<m;++i){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        solders = vector<pair<int, int> > (Nsolder);
        for( int i = 0;i<Nsolder;++i){
            cin>>x>>y;
            solders[i] = make_pair(x,y);
        }
        vi_sno = vector<int> (n+1);
        fill_n(vi_sno.begin(), n+1, 0);
        vi = vector<bool> (n+1);
        fill_n(vi.begin(), n+1, false);
        di = vector<int> (n+1);
        fill_n(di.begin(), n+1, 0);
    }
    bool bfs(pair<int,int> s){
        if( vi[s.first])
            return false;
        vi[s.first] = true;
        vi_sno[s.first] = s.first;
        queue<int> q;
        q.push(s.first);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for( auto ed:g[v]){
                if( di[v]+1 <=s.second){
                    if( !vi[ed] ){
                        q.push(ed);
                        di[ed] = di[v]+1;
                        vi[ed] = true;
                        vi_sno[ed] = s.first;
                    }
                    else if( vi_sno[ed] !=s.first){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void sol(){
        bool flag = true;
        for( auto solder:solders){
             flag= bfs(solder);
            if( !flag) break;
        }
        for(int i =1;i<=n;i++){
            if( vi[i] = false){
                flag = false;
                break;
            }
        } 
        if( !flag ) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        
    }
};

int main(void ){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        graph g;
        g.inpg();
        g.sol();
    }
    return 0;
}