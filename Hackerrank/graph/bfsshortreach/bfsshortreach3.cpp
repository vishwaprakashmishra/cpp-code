#include <iostream>
#include <queue>

using namespace std;

#define MAXV    1000

struct edgenode{
    int y;
    int weight;
    edgenode *next;
};

struct graph{
    edgenode *edges[MAXV + 1];      /* Adjacency info */
    int outdegree[MAXV + 1];        /* outdegree of each vertex */  
    int nvertices;                  /* no of vertices of graph */
    int nedges;                     /* no of edges of the graph */
    bool directed;                  /* is the graph directec */
};

void init_graph(graph *g, bool directed){       /* initializing the graph */
    int i ;                                     /* counter for iteration */
    
    g->nvertices = 0;                           /* initially the no of vertices is 0 */
    g->nedges = 0;                              /* inttially there is no edges added in the graph */
    g->directed = directed ;                    /* initializing if the if the graph is directed of not */
    
    for (i = 1 ; i <= MAXV ; i++ )              /* Loop for initializing the outdegree of all the vertices initially to be zero */
    {
        g->outdegree[i] = 0;                    /* initiallized all outdegree to be zero */
        g->edges[i] = NULL;                     /* all list of edges pointing to NULL */
    }
}

void insert_edge( graph *g, int x , int y  , bool directed){
    edgenode *p;
    p = new edgenode;
    p->weight = 6 ;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p;
    g->outdegree[x]++;
    
    if(directed == false)
        insert_edge(g, y, x, true);
    else 
        g->nedges++;
}

void read_graph(graph *g , bool directed)
{
    int i ;                                 /* counter */
    int m ;                                 /* number of edges */
    int x, y;                               /* vertices to edges (x, y) */
    
    init_graph(g, directed);                /* graph is initialize */
    cin>>g->nvertices>>m;                   /* entered the no_of_vertices and no_of_edges */
    
    for( i = 1 ; i <= m ; i++ ){ 
        cin>>x>> y;
        insert_edge(g, x , y, directed);    /* inserting the edge */
    }
}

void display_graph(graph *g){
    int i ;                     /* counter */
    edgenode *p;                /* temporary pointer */
    
    for(i = 1; i <= g->nvertices ; i++ )
    {
        cout<< i << " ->";
        p = g->edges[i];
        while(p  != NULL)
        {
            cout<<p->y<< " " ;
            p = p->next;
        }
        cout<<endl;
    }
}

/*
void outdeg(graph *g){
    for(int i = 1 ; i <= g->nvertices ; i++ )
    {
        cout<< i << "-> " << g->outdegree[i] << " " ;
    }
}
*/

bool discovered[MAXV + 1];
int parent[MAXV + 1];
int wt[MAXV + 1] ; 

void init_search(graph *g){
    int i ;
    for( i = 1; i <= g->nvertices ; i++ )
    {
        discovered[i] = false;
        wt[i] = -1;
        parent[i] = -1;
    }
}

void bfs(graph *g, int start){
    queue<int> q;
    int v;
    int y;
    edgenode *p;    /*temporary pointer */
    
    q.push(start);
    discovered[start] = true;
    wt[start] = 0;
    
    while( !q.empty() )
    {
        v = q.front();
        q.pop();
        
        p = g->edges[v];
        
        while( p != NULL) {
            y = p->y;
                            
            if( !discovered[y] ){
                cout<< y << " " ;
                q.push(y);
                wt[y ] = wt[v] + 6;
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
    }
}

void print_ans(graph *g){
    for(int i = 1 ; i <= g->nvertices ; i++ )
    {
        if(wt[i] == 0)
            continue;
        cout<< wt[i] << " ";
    }
}

int main(){
    int t;
    cin>>t;
    
    while ( t> 0)
    {
        int S;
        graph *g;
        
        g = new graph;
        read_graph(g, false);   /* problems lies in read graph's allocation of memory */

        cin>>S;
        display_graph(g);
        init_search(g);
        bfs(g, S);
        print_ans(g);
        cout<<endl;
        delete g;
        t--;
    }
    return 0;
}