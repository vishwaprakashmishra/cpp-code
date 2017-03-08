#include<iostream>
#include <climits>

#define MAXV  3001
using namespace std; 

struct edgenode{
    int y, weight;
    edgenode *next;
   
};

struct graph {
    edgenode *edges[MAXV + 1];
    int outdegree[MAXV + 1], nedges, nvertices;
    bool directed;
    
};

void init_graph( graph *g, bool directed){
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    
    int i ;
    for ( i =  1; i <= MAXV ; i++ )
    {
        g->outdegree[i ]  = 0;
        g->edges[i] = NULL;
    }
}

void insert_edge( graph *g, int x , int y , int weight, bool directed  )
{
    edgenode *p;
    p = new edgenode;
    p->y = y;
    p->weight = weight;
    p->next  = g->edges[x];
    g->edges[x] = p;
    g->outdegree[x]++ ;
    
    if( directed == false )
        insert_edge(g, y , x, weight , true);
    else 
        g->nedges++ ;
}

void read_graph( graph  *g, bool directed){
    int i ; 
    int m;
    int x, y , weight; 
    init_graph(g, directed);
    cin>> g->nvertices>>m;  /* no of vertices and no of edges */
    
    for ( i = 1; i <= m; i++)
    {
        cin>> x>> y >> weight;
        insert_edge(g, x, y , weight, directed );
    }
}


void prim(graph *g, int start)
{
    int i ;
    edgenode *p; 
    int parent[MAXV + 1];
    bool intree[MAXV + 1];
    int distance[MAXV + 1];   
    int v;           
    int y;
    int weight,dist,ans = 0;    
    for(i = 1 ; i<=g->nvertices ; i++ ) {
        intree[i] = false ;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[start] = 0;
    v = start;
    while (intree[v] == false )
    {
        intree[v] = true;
        p = g->edges[v] ; 
        while ( p !=NULL )
        {
            y = p->y;
            weight = p->weight;
            if ((distance[y] > weight) && (intree[y] == false)){
                distance[y]  = weight;
                parent[y] = v;  
            }
            p = p->next;
        }
        v = 1;
        dist = INT_MAX;
        for ( i = 1; i <= g->nvertices ; i++ )
        {    
            if((intree[i] == false ) && (dist > distance[i])) {
                dist = distance[i];
                v = i;
            }
        }
        if ( dist != INT_MAX)
            ans += dist;
    }
    cout<<ans<<endl;    
}

int main()
{
    int start;
    graph *g;
    g = new graph ;
    read_graph(g, false);
    cin>>start;
    prim(g,start );    
    delete g; 
}