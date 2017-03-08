#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
struct uf{
    vector<int> par;
    vector<pair< int, int> > g;
    int n,m;
    
    void inpg(){
        int x, y;
        cin>>n>>m;
        par = vector<int>(n+1);
        fill_n(par.begin(), n+1, -1);
        g = vector<pair<int, int> > (m);
        for( int i=0;i<m;i++){
            cin>>x>>y;
            g[i] = make_pair(x,y);
        }
    }
    void sol(){
       int x =0;
        for( auto ed:g){
            x = uni(ed.first,ed.second);
            if( x ==1) break;
        }
        if( x ==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    int find(int x){
        if( par[x] == -1) return x;
        else return find(par[x]);
    }
    int uni(int x, int y){
        if( find(x) == find(y)) return 1;
        else par[x] = y;
        return 0;
    }
};
int main(void){
    uf g;
    g.inpg();
    g.sol();
    return 0;
}