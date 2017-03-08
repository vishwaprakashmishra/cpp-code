#include<iostream>
#include <climits>

#define MAXV  3001;
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

void init_graph ( graph *g, bool directed){
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    
    int i ;
    for ( i =  1; i <= MAXV ; i++ )
    {
        g->outdegree[i ]  =0;
        g->edges[i] = nullptr;
    }
}

void insert_edge( graph *g, int x , int y , int weight, bool directed  )
{
    edgenode *p;
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
    
    cin>> g->nvertices>>m;  /* no of vertices and no of edges */
    
    for ( i = 1; i <= g->nvertices; i++   )
    {
        cin>> x>> y >> weight;
        insert_edge(g, x, y , weight, directed );
    }
}

int print_graph( graph * g)
{
    int i ; 
    int y;
    edgenode *p;
    for(i = 1; i < g->nvertices ; i++ )
    {
        p = g->edges[i];
        while ( p != nullptr)
        {
            y = p->y ; 
            cout<< y<< " " ;
            p= p->next;  
        }
        cout<<endl;
    }
}

int parent[MAXV + 1];
bool intree[MAXV + 1]
int distance[MAXV + 1];

void prim(graph * g, int start)
{
    int i ;
    edgenode *p;    
    int v;           
    int y;
    int weight;
    int dist;
    
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
            if ((distance[y] == weight) && (intree[y] == false)){
                distance[y]  = weight;
                parent[y] = v;
                
            }
            p = p->next;
        }
        v = 1;
        dist = INT_MAX;
        for ( i = 1; i <= g->nvertices ; i++ )
            if((intree[i] == false ) && (dist > distance[i])) {
                dist = distnce[i];
                v = i;
            }
    }    
}

void print_ans(graph *g )
{
    int i ;
    for ( i= 1; i <= g->nvertices ; i++ )
    {
        
    }
}
int main()
{
    int t;
    int s;
    cin>> t;
    while( t > 0)
    {
        graph *g;
        g = new graph ;
        
        read_graph(g, true);
        
        print_graph(g);
        cout>>s;
        prim(g,s );
        print_ans();
        
        delete g;
        t--;
    }
}