#include<bits/stdc++.h>
using namespace std;
struct graph{
    vector<vector<int> > g;
    vector<vector<bool> > vi;
    vector<int> sliks;
    int  m , n;
    
    void inpg(int n,int m){
        this->n=n;
        this->m=m;
        g = vector<vector<int> > (n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin>>g[i][j];
         }
    }
    void edges(pair<int,int> e, vector<pair<int,int> > &eds){
        eds= vector<pair<int,int> > ();
        if( e.first-1 >=0 && g[e.first-1][e.second]==1)
            eds.push_back(make_pair(e.first-1,e.second));
        if( e.first+1 <n && g[e.first+1][e.second]==1)
            eds.push_back(make_pair(e.first+1,e.second));
        if( e.second-1 >=0 && g[e.first][e.second-1] ==1)
            eds.push_back(make_pair(e.first,e.second-1));
        if( e.second+1 <m && g[e.first][e.second+1] ==1)
            eds.push_back(make_pair(e.first,e.second+1));
    }
    int bfs(pair<int,int> s){
        int siz=1;
        vi[s.first][s.second]=true;
        queue<pair<int,int> > q;
        q.push(s);
        while(!q.empty()){
            pair<int,int> v;
            v = q.front();
            q.pop();
            vector<pair<int,int> >eds;
            edges(v,eds);
            siz++;
            for( auto ed:eds){
                if(!vi[ed.first][ed.second])
                {
                    vi[ed.first][ed.second] = true;
                    
                    q.push(ed);
                }
            }
        }
        return siz;
    }
    void conn(){
        
        sliks = vector<int>();
        vi = vector<vector<bool> > (n,vector<bool> (m));
        for(int i=0;i<n;i++) fill_n(vi[i].begin(),m,false);
        for( int i = 0;i<n;++i)
        {
            for( int j = 0;j< m;j++){
                if( g[i][j] ==1 && vi[i][j]==false ){
                    pair<int,int> p;
                    p = make_pair(i,j);
                    sliks.push_back(bfs(p) );
                }
            }
        }
        sort(sliks.begin(),sliks.end());
        int c,s_siz=1;
        c = sliks[0];
        if( sliks.size()==1)
        cout<<sliks[0]<<" "<<"1";
        else {
        for( int i=1;i<sliks.size();i++){
           
            if(c == sliks[i]){
                s_siz++;
            }
            else{
                c = sliks[i];
                cout<<sliks[i-1]<<" "<<s_siz<<endl;
                s_siz=1;
            }
        }
        cout<<sliks[sliks.size()-1]<<" "<<s_siz<<endl;
        }
    }
};
int main()
{
    int m,n;
    while(true){
        graph g;
        cin>>n>>m;
        if( n==0 && m==0)
            break;
        else {
            g.inpg(n,m);
        }
        g.conn();
    }
    return 0;
}