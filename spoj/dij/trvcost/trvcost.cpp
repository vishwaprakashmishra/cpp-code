// tag graph-theory and dijkstra-s-algorithm
#include<bits/stdc++.h>
using namespace std;
class comp{
    bool operator()(pair a, pair b ){
        return a.second < b.second;
    }
};
class graph{
  public:
    vector<vector<pair<int, int> > > g;
    int n,source ;
    void inp(){
        cin>>n;
        int a, b , w;
        g = vector<vector<pair<int, int> > > (501,vector<pair<int, int> >());
        
        for( int i =0;i<n;i++){
            cin>>a>>b>>w;
            g[a].push_back(make_pair(b,w));
            g[b].push_back(make_pair(a,w));
        }     
        
    }  
    void dij(int s){
        priority_queue<pair<int, int> , vector<pair<int, int> > , comp) q;
        q.insert(make_pair(s,0));
        vi = vector<bool> (501);
        fill_n(vi.begin(), 501, false);
        vi[s ] = true;
        di[s] = 0;
        while(!q.empty())
        {
            pair<int, int> v = q.top();
            q.pop();
            for( auto ed:g[v.first]){
                if(di[ed.first] > di[v.first] + ed.second){
                    di[ed.first] = di[v.first] + ed.second;
                    q.insert(ed);
                    par[ed.first] = v.first;
                }
            }
        }
        cin>>q;
        while(q--){
            int d;
            cin>>d;
            if( vi[d])
            {
                printP(s,d);
            }
            else cout<<source<<"->"<<d<<"= no path exist between "<<source<<"and "<<d<<endl;
        }
    }
    void printP(int s, int d){
        stack<int> s;
        s.push(d);
        int counter=d;
        while(counter != s){
            counter = par[counter];
            s.push(counter);
        }
        s.pop();
        for(int i=0;i<s.size(), ++i){
            counter = s.top();
            cout<<"->"<<counter
        }
    }
};
int main(void){
    return 0;
}