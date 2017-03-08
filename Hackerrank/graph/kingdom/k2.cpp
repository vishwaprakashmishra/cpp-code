#include<iostream>
#include<vector>
#include<algorithm>
enum Color {WHITE, GRAY, BLACK};
using namespace std;
struct graph {
    vector<vector<int> > g;
    int m,n, end, path, cycle_in_the_path;
    vector<bool> vi;
    vector<int> color,path_status, par;// 0 for no-path , 1 for path
    void inp(){
        int x, y;
        cin>>n>>m;
        g = vector<vector<int> > ( n+1, vector<int> ());
        for( int i=0;i<m;i++){
            cin>>x>>y;
            g[x].push_back(y);
        }
        vi = vector<bool>(n+1);
        color = par =path_status = vector<int> (n+1);
        path =0;
        end =n;
        cycle_in_the_path = 0;
        
        fill_n(vi.begin(), n+1, false);
        fill_n(path_status.begin(), n+1, -1);
        fill_n(par.begin(), n+1, -1);
        fill_n(color.begin(),n+1, WHITE);
    }
    int dfs(int s){
        vi[s] = true;
        color[s] = GRAY;
        
        
        for( auto ed:g[s]){
            if( !vi[ed]){
                color[ed] = GRAY;
                par[ed] = s;
                int rs = dfs(ed);
                if ( rs == 2)
                    return 2;
                if(rs == 1){
                    path_status[s] = 1;
                }
            }
            else if( vi[ed]){
                if(path_status[ed]){
                    path_status[s] = 1;
                    path++;
                }
            }
            else if( color[ed]==GRAY){
                cycle_in_the_path = ed;
            }
            
        }
        if(s == end){
            path++;
            path_status[end]= 1;
            color[s] = BLACK;
            if( cycle_in_the_path)
                return 2;
            else return 1;
        }
        if( g[s].size()==0){
            return 0;
        }
        else if( path_status[s]==1) return 1;
        else return 0;
    }
};
int main(void){
    int s;
    graph g;
    g.inp();
    g.dfs(1);
    cout<<g.path<<endl;
    return 0;
}