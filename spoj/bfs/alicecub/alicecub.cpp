#include<bits/stdc++.h>
using namespace std;
class graph{
  public:
    int n ;
    vector<vector<int> > g;
    vector<int> bulbs;
    vector<pair<int, int> > ans;// first = point , sec = dist
    graph(){
        bulbs = vector<int> (17);
        for(int i=1;i<=8;i++){
            g[i].push_back(i+8);
        }    
        g[9].push_back(10);
        g[9].push_back(11);
        g[9].push_back(13);
        g[10].push_back(12);
        g[10].push_back(14);
        g[10].push_back(9);
        g[11].push_back(9);
        g[11].push_back(12);
        g[11].push_back(15);
        g[12].push_back(10);
        g[12].push_back(11);
        g[12].push_back(16);
        g[13].push_back(9);
        g[13].push_back(14);
        g[13].push_back(15);
        g[14].push_back(10);
        g[14].push_back(14);
        g[14].push_back(16);
        g[15].push_back(11);
        g[15].push_back(13);
        g[15].push_back(16);
        g[16].push_back(12);
        g[16].push_back(14);
        g[16].push_back(15);
    }
    void in(){
        for(int i =1;i<=16; ++i) cin>>bulbs[i];
    }
    int bfs(int s, int limit ){
        vi[s] = true;
        queue<int> q;
        q.push(s);
        while( !q.empty()){
            int v = q.front();
            q.pop();
            for(auto ed:g[v]){
                if( !vi[ed] && di[v]+1 <=limit){
                    di[ed] = di[v]+1;
                    if(bulb[ed] = 0) {
                        ans.push_back(make_pair(ed, di[ed]));
                    }
                    q.push(ed);
                }
            }
        }
    }
    void sol(){
        ans = vector<pair<int, int> > ();// ans is initialized
        vector<int > points;
        points = vector<int> ();
        for( int i = 1;i<=8;i++)
            if( bulbs[i] == 1) 
                points.push_back(i);
        if( points.size() > 3){
            cout<<"more"<<endl;
            return ;
        }     
        else if( points.size() == 3) {
            for( int i =0;i<3;i++){
                if(bulb[points[i]+8] == 0){
                    continue;
                } 
                else {
                    cout<<"more"<<endl;
                    return ;
                }
            }
            cout<<"3"<<endl;
        }
        else if( poitns.size() == 0) {
            cout<<"0"<<endl;
            return ;
        }
        else if(points.size() == 1)
        {
            bfs(points[0], 3);
            if( sol.size() ==1) cout<<ans[0].second<<endl;
        }
        else {
            bfs(points[0],2);
            bfs(points[1],2);
            // dynamic programing check
            if( ans.size() == 4)
                cout<<"2"<<endl;
            else if( ans.size() == 3) 
            {}
        }
    }
};
int main(void){
    graph g;
    int t ;
    cin>>t;
    while(t--){
        g.in();
        g.sol();
    }
    return 0;
}