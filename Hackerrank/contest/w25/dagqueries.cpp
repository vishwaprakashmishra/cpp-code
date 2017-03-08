#include<bits/stdc++.h>
using namespace std;
class graph{
  public:
    int n, m, q;
    vector<vector<int> > g;
    void in(){
        cin>>n>>m>>q;
        int x, y;
        g = vector<vector<int> > (n+1, vector<int> ());
        for( int i=0;i<m;i++){
            cin>>x>>y;
            g[x].push_back(y);
        }
    }  
    
};

int main(void){
    return 0;
}