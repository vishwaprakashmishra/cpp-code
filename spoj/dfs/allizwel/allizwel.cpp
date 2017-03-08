#include<iostream>
#include<vector>
#include<string>
using namespace std;

class graph {
  public:
    int r , c;
    vector<string> g;
    string p;
    void in(){
        cin>>r>>c;
        p = "ALLIZZWELL";
        g = vector<string> (r);
        for(int i=0;i<r;i++) cin>>g[i];
    }
    bool sol(){
        vector<pair<int, int> > point(0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if( g[i][j] == 'A') 
                    point.push_back(make_pair(i,j));
            }
        }
        // points aquired
        for(auto p:point){
            if(Alliswell(p.second, p.first, 0)) return true;
        }
        return false;
    }
    bool Alliswell(int x, int y, int pos){
        if( pos = p.size()-1 && g[x][y] == p[p.size()-1] )
            return true;
        else if( pos == p.size()-1) 
            return false;
        // like for loop
        vector<bool> returns(8);
        if( x-1 >=0 && y-1 >=0){
            if(g[y-1][x-1] == p[pos+1]) 
                returns[0] =Alliswell(x-1, y-1, pos+1);
            if(g[y][x-1] == p[pos+1]) 
                returns[1] = Alliswell(x-1, y, pos+1);
            if(g[y-1][x] == p[pos+1] ) 
                returns[2] =Alliswell(x, y-1, pos+1);
            if( y+1 <r  && g[y+1][x-1] == p[pos+1]) 
                returns[3] =Alliswell(x-1, y+1, pos+1);
            if( x+1 <c && g[y-1][x+1] == p[pos+1] ) 
                returns[4] = Alliswell (x+1, y-1, pos+1);
        }
        if( x+1<c && y+1<r) {
            if(g[y+1][x+1] == p[pos+1]) 
                returns[5] =Alliswell(x+1, y+1, pos+1);
            if( g[y][x+1] == p[pos+1]) 
                returns[6] =Alliswell(x+1, y, pos+1);
            if( g[y+1][x] == p[pos+1] ) 
                returns[7] =Alliswell(x, y+1, pos+1); 
        }
        for( auto e:returns)
            if( e == true) return true;
        return false;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        graph g; 
        g.in();
        if( g.sol()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}