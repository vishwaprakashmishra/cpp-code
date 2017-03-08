#include<bits/stdc++.h>
using namespace std;
struct graph{
    int n, m;
    vector<vector<int> > g;
    vector<bool> vi;
    vector<int > di;
    
    void inpg(){
        int x, y;
        cin>>n;
        g = vector<vector<int> > (n,vector<int> ());
        for(int i=0;i<n-1;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vi = vector<bool> (n);
        di= vector<int> (n);
        
    }
    void bfs(int s){
        queue<int> q;
        q.push(s);
        vi[s] = true;
        di[s] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for( auto ed:g[v]){
                if( !vi[ed] ){
                    vi[ed] = true;
                    di[ed] = di[v] +1;
                    q.push(ed);
                }
            }
        }
    }
    void sol()
    {
        fill_n(vi.begin(), n, false);
        fill_n(di.begin(), n , 0);
        int maxi = 0, index = 0;
        bfs(1);
        for( int i=0;i<n;i++){
            if( maxi<di[i]){
                index = i;
                maxi = di[i];
            }
        }
        fill_n(di.begin(), n, 0);
        fill_n(vi.begin(), n , false);
        bfs(index);
        maxi = *max_element(di.begin(), di.end());
        if( maxi%2== 0) cout<< maxi/2<<endl;
        else cout<<(maxi+1)/2<<endl;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        graph g;
        g.inpg();
        g.sol();
        
    }
    return 0;
}