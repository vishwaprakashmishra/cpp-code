#include<bits/stdc++.h>
using namespace std;
#define MAX         10000
#define MOD         1000000000
#define white       0
#define grey        1
#define black       2

typedef long long int LL;

int src, dest, n, m;
vector<int> edges[MAX+10], reverse_edges[MAX+10];
int vis[MAX+10];
bool cycle_reachable_from_src[MAX+10];
LL dp[MAX+10];

void dfs(int node, vector<int>G[], bool cycle[])
{
    vis[node] = grey;
    for(int i = 0; i<G[node].size(); i++)
    {
        int v = G[node][i];
        if(vis[v] == white)
            dfs(v, G, cycle);
        else if(vis[v] == grey)
            cycle[v] = true;
    }
    vis[node] = black;
}

void dfs(int node, vector<int>G[])
{
    vis[node] = grey;
    for(int i = 0; i<G[node].size(); i++)
    {
        int v = G[node][i];
        if(vis[v] == white)
            dfs(v, G);
    }
    vis[node] = black;
}

// We need to find a cycle that is reachable from both the source anode the destination
bool check_cycle()
{
    dfs(src, edges, cycle_reachable_from_src);

    memset(vis, 0, sizeof(vis));
    dfs(dest, reverse_edges);
    for(int i = 1; i<=n; i++)
    {
        // check if node i is a part of a cycle which is reachable from source in the main
        // graph anode also reachable from destination in the reverse graph.
        if(cycle_reachable_from_src[i] && vis[i] == black)
            return true;
    }
    return false;
}
LL call(int node)
{
    if(cycle_reachable_from_src[node] == true)
        return 0;
    if(node == dest)
        return 1;
    if(dp[node] != -1)
        return dp[node];

    LL ret = 0;
    for(int i = 0; i<edges[node].size(); i++)
    {
        int v = edges[node][i];
        ret = (ret + call(v))%MOD;
    }
    return dp[node] = ret;
}
int main()
{
    int i, j, u, v;
    cin >> n >> m;
    for(i = 1; i<=m; i++)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        reverse_edges[v].push_back(u);
    }
    src = 1, dest = n;

    memset(dp, -1, sizeof(dp));
    if(check_cycle())
        printf("INFINITE PATHS\n");
    else
        printf("%lld\n",call(src));
}