#include <iostream>
using namespace std ;
#define MAXV  1000

struct edgenode {
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

void init_graph( graph * g , bool directed)
{
    int i;
    g->nedges = 0;
    g->nvertices  = 0;
    g->directed = directed ; 
    
    for ( i = 1 ; i <= MAXV ; i++ )
    {
        g->outdegree[i]  = 0;
        g->edges[i] = NULL;
    }
}

void insert_edge( graph * g, int x, int y  , bool directed ) 
{
    edgenode *p;
    p = new edgenode;
    p->y = y;
    p->weight = 0;
    p->next = g->edges[x];
    g->edges[x] = p;
    g->outdegree[x]++ ;
    
    if( directed = false )
        insert_edge(g, y , x, true);
    else 
        g->nedges++ ;
    
}

void input_graph ( graph * g , bool directed)
{
    int i ;
    int m ;
    int x, y;
    init_graph(g, directed);
    
    cin>> g->nvertices>> m;
    
    for (i  = 1 ; i <= m ; i++ ){
        cin>>x>>y;
        insert_edge(g, x, y , directed);
        
    }
}

void display_graph ( graph *g)
{
    int i ; 
    edgenode *p;
    for ( i = 1; i <= g->nvertices ; i++ )
    {
        cout<< i << " -> " ;
        p = g->edges[i];
        while(p != NULL)
        {
            cout<< p->y<< " " ;
            p = p->next;
            
        }
        cout<< endl;
    }
}

/* 
void outdeg(graph *g){
    for( int i = 1 ; i <= g->nvertices ; i++ )
    {
        cout<< i << " ->" << g->outdegree[i]<< " ";
    }
}

*/
