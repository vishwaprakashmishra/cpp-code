#include <iostream>
#include <climits>
using namespace std;
#define MAXV 400
#define MAXINT INT_MAX/400


struct adjacency_matrix{
    int weight[MAXV + 1][MAXV + 1];
    int nvertices ;
    
};

void create_graph(adjacency_matrix *g)
{
    int i , j;
    int x;
    int y;
    int weight;
    int m;
    
    cin>> g->nvertices>> m ;
    
    for ( i  = 1; i <= g->nvertices ; i++ )
        for ( j = 1 ; j <= g->nvertices ; j++ )
        {
            g->weight[i][j] = MAXINT; 
        }
    for ( i = 1; i <= m ; i++ )
    {
        cin>> x>> y>> weight;
        g->weight[x][y] = weight;
    }
    
}
void floyd(adjacency_matrix *g)
{
    int i, j;
    int k;
    int through_k;
    
    for ( k = 1 ; k <= g->nvertices ; k++ )
        for ( i = 1 ; i <= g->nvertices ; i++ )
            for  ( j = 1 ; j <= g->nvertices ; j++ )
            {
                through_k =  g->weight[i][k] + g->weight[k][j];
                if ( through_k < g->weight[i][j])
                g->weight[i][j] = through_k;
            }
}

int main()
{
    int i;
    int Q;
    int x,y,weight;
    adjacency_matrix *g;
    g = new adjacency_matrix;
    create_graph(g);
    
    floyd(g);
    cin>> Q;
    for ( i= 1 ; i <= Q ; i++ )
    {
        cin>>x>> y;
        weight = g->weight[x][y];
        if( x == y )
            cout<< "0" <<endl;
        else if( weight < 140005)
            cout<<weight<<endl;
        else 
            cout<< "-1"<<endl;
            
    }
}