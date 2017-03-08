#include<bits/stdc++.h>
using namespace std;
struct graph {
    int n, q ,r;
    vector<vector<int> > g;
    vector<int > depth;
    vector<bool> vi;
    vector<int > maxdi;
    
    void inpg(){
        ios_base::sync_with_stdio(false);
        int x ,y ;
        cin>>n;
        g = vector<vector<int> > (n+1, vector<int> ());
        for( int i=0;i<n-1;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cin>>r>>q;
        vi = vector<bool> (n+1);
        depth = vector<int> (n+1);
        maxdi = vector<int> (n+1);
    }
    int dfs(int s){
        vi[s] = true;
        int temp=0 , fir=0, sec = 0, superMaxdi = 0;
        for( auto ed:g[s]){
            if( !vi[ed]){
                
                temp = dfs(ed);
                if( temp > fir){
                    swap(sec, fir);
                    fir = temp;
                }
                else if( temp > sec)
                    swap( temp , sec);
                if( superMaxdi < maxdi[ed])
                    superMaxdi = maxdi[ed];
            }
        }
        if( fir + sec > superMaxdi) 
            maxdi[s] = fir + sec;
        else maxdi[s] = superMaxdi;
        depth[s] = fir;
        return fir+1;
    }
    void sol(){
        int query;
        int so = dfs(r);
        for( int i = 0 ;i < q;++i){
            cin>>query;
            cout<<maxdi[query]<<endl;
        }
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    graph g;
    g.inpg();
    g.sol();
    return 0;
}