#include< iostream>
using namespace std;
#define MAXV 1000

struct edgenode{
    int y;
    int weight;
    edgenode *next;
};

struct graph {
    edgenode *edges[MAXV + 1];
    int outdegree[MAXV + 1];
    int nvertices;
    int nedges ;
    bool directed ;
};

void init_graph( grpah *g, bool directed)
{
    int i ;
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    
    for ( i = 1; i <= MAXV ; i++ )
    {
        g->edges[i] = nullptr ;
        g->outdegree[i] = 0;
    }
}

void insert_edge(graph *g, int x , int y , int weight , bool directed)
{
    int i ;
    edgenode *p;
    p->y  = y ; 
    p->weight  = weight;
    p->next = g->edges[x];
    g->edges[x] = p;
    g->outdegree[x]++ ;
    
    if( !directed) 
        insert_edge(g, y , x, weight , true);
    else 
        g->nedges++ ;
}

void read_graph ( graph *g, bool directed)
{
    int i ;
    int m;
    int weight;
    int x , y;
    
    cin>> g->nvertices>>m;
    
    for( i = 1; i <=g->nvertices; i++ )
    {
        cin>> x>> y >> weight;
        insert_edge(g, x, y , weight , directed);
    }
}

void display_graph ( graph * g)
{
    int i ;
    edgenode *p;
    
    for ( i = 1; i <= g->nvertices ; i++ )
    {
        p = g->edges[i];
        cout<< i << " -> ";
        while( p != nullptr)
        {
            int y ; 
            y = p->y;
            cout<< y;
            p = p->next;
        }
        cout<< endl;
    }
}

int main()
{
    int t ; 
    cin>> t;
    while( t >0)
    {
        graph *g;
        g = new graph ; 
        read_graph(g, false);
        
        display_graph(g);
        /* any algoorithim you want to write in this area */
        cin>> s;
        
        do_function ( g, s);
        display_ans();
        /* any algorithim you want to write in this area */
        
        delete g;
        t-- ;
        
    }
    return 0;
}
