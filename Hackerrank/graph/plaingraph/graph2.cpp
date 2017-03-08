#include<iostream>
#include <climits>

#define MAXV  3001
using namespace std; 

struct edgenode{
    int y;
    int weight;
    edgenode *next;
   
};

struct graph {
    edgenode *edges[MAXV + 1];
    int outdegree[MAXV + 1];
    int nedges;
    int nvertices;
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
    
    if( !directed )
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
