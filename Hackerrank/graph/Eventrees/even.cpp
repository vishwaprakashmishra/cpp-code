#include<bits/stdc++.h>

using namespace std;
class tree{
    public:
    int *p, *size, n;
    tree(int a){
        p  = new int[a+1];
        size = new int[a+1];
        fill_n(p, a+1, -1);
        fill_n(size, a+1, 1);
        n = a;
    }
    void update(int w , int wt)
    {
        if(p[w] != -1){
            size[p[w]] += wt;
            update(p[w],wt);
        }
    }
    void makeTree(int n){
        int u,v,i;
        for ( i = 1 ;  i <= n ; i++ ){
            cin>>u>>v;
            if( (size[u] > 1)||(p[u] != (-1) )){
                update(u,1);
                p[v] = u;
                size[u] +=1;
            }
            else if(  (size[v] > 1) || (p[v] != (-1)) )
            {
                update(v,1);
                p[u] = v;
                size[v]+=1;
            }
            else {
                p[u] = v;
                size[v] = 2;
            }
        }
    }
    void removeEdge(int parent, int child){
        p[child] = -1;
        size[parent] -= size[child];
        update(parent, (0 - size[child]));
        size[child] = INT_MAX;
    }
    void solution()
    {
        int i , min_even = INT_MAX, sol = 0, child;
        bool endof = false ;
        
        while( endof == false )
        {
            min_even = INT_MAX;
            for ( i = 1 ; i <= n; i++ )
            {
                if(size[i]%2 == 0 && size[i] < min_even)
                {    
                    min_even = size[i];
                    child = i;
                }   
            }
            if( min_even == INT_MAX ){
                endof = true;
                break;
            }
            else {
                removeEdge(p[child], child);
                sol++ ;
            } 
        }
        cout<< sol-1;
    }
};
int main()
{
    int n , m;
    cin>>n>>m;
    tree t(n);
    t.makeTree(m);
    t.solution();
    return 0;
}