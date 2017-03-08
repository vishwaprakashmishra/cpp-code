#include<bits/stdc++.h>
using namespace std;
struct graph {
    vector<vector<int> > g;
    vector<vector<bool> > vi;
    vector<pair<int,int> > eds;
    void ini(){
    g = vector<vector<int> > (8, vector<int> (8));
    vi =vector<vector<bool> > (8,vector<bool> (8));
    }
    void edges(pair<int,int> e, vector<pair<int,int> > &eds){
        eds  = vector<pair<int,int> > ();
        if( e.first-2>=0 & e.second-1>=0 )
            eds.push_back(make_pair(e.first-2,e.second-1));
        if( e.first-2>=0 && e.second+1<=7)
            eds.push_back(make_pair(e.first-2,e.second+1));
        if( e.first-1>=0 && e.second-2>=0)
            eds.push_back(make_pair(e.first-1,e.second-2));
        if( e.first-1>=0 && e.second+2 <=7)
            eds.push_back(make_pair(e.first-1,e.second+2));
        if( e.first+1<=7 && e.second-2 >=0)
            eds.push_back(make_pair(e.first+1,e.second-2));
        if( e.first+1<=7 && e.second+2 <=7)
            eds.push_back(make_pair(e.first+1,e.second+2));
        if( e.first+2<=7 && e.second-1 >=0)
            eds.push_back(make_pair(e.first+2,e.second-1));
        if( e.first+2 <=7 && e.second+1 <=7)
            eds.push_back(make_pair(e.first+2,e.second+1));
    }
    int bfs(pair<int,int> s, pair<int,int> ends){
        
         vector<vector<int> > di(8,vector<int> (8));
        for( int i=0;i<8;i++) fill_n(di[i].begin(),8,0);
        di[s.first][s.second]=0;
        
        vi[s.first][s.second] = true;
        queue<pair<int,int> > q;
        q.push(s);
        while( !q.empty()){
            pair<int,int> v;
            v = q.front();
            q.pop();
            edges(v,eds);
            for( auto ed:eds){
                if( !vi[ed.first][ed.second]){
                    q.push(ed);
                    vi[ed.first][ed.second]=true;
                    di[ed.first][ed.second]=di[v.first][v.second]+1;
                    if( ed == ends)
                    {
                        cout<<di[ed.first][ed.second]<<endl;
                        return 0;
                    }
                }
            }
        }
        return 1;
        
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        graph g;
        string st,en;
        cin>>st>>en;
        pair<int,int> sti,eni;
        sti.first = st[0]-'a';
        sti.second = st[1]-'1';
        eni.first = en[0]-'a';
        eni.second = en[1] -'1';
        g.ini();
        int a =g.bfs(sti,eni);
    }
    return 0;
    
}