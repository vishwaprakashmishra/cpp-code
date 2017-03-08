#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,w;
    bool operator<(node n){
        return this->w < n.w;
    }
    bool operator>(node n){
        return this->w> n.w;
    }
};
struct graph{
    vector<node> g;
    int m, n, p;
    long long int mst_wt;
    vector<int > par;
    
    void inpg(){
        node a;
        cin>>p;
        cin>>n>>m;
        for(int i =0;i<m;++i){
            cin>>a.x>>a.y>>a.w;
            g.push_back(a);
        }            
        mst_wt = 0;
    }
    int fi(int x){
        if( par[x] == -1 ) return x;
        else return fi(par[x]);
    }
    
    void uni(int x, int y , int w)
    {
        if( !(fi(x)==fi(y))){
            par[fi(x)] = fi(y);
            mst_wt += w;
        }
    } 
    void sol(){
        par = vector<int> (n+1);
        fill_n(par.begin(), n+1, -1);
        sort(g.begin(), g.end()) ;
        for( auto ed:g){
            uni(ed.x, ed.y, ed.w);
        }
        cout<<mst_wt*p<<endl;
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