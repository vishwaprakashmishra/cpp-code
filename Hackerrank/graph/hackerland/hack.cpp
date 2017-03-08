#include <bits/stdc++.h>

using namespace std;

vector<pair<int ,int> > g;
void kruskal(vector<pair<int,int > > &graph)
{
    
}
bool processed[MAXV + 1];
int count ;

void init_dfs()
{
    for( int i = 1 ; i <= MAXV ;i++ )
    {
        processed[i] = false ; 
    }
    count = 0;
}

void dfs(int start )
{
    processed[start] = true ;
    for ( int i = 1 ; i <= h[start].size() ; i++ )
    {
        if( !processed[g[start][i].first])
        {
            dfs(h[start][i].first);
            count+=1;
        }
    }
}
int main()
{
    int i;
    int n, m;
    int x, y, wt;
    pair <int , int > p;
    cin>> n>> m;
    for ( i = 1; i <= m ;i++ )
    {
        cin>>x>>y>>wt;
        p.first = y;
        p.second = wt;
        g[x].push_back(p );
        p.first = x;
        g[y].push_back(p);
        
    }
    
    
}