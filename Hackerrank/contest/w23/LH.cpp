#include<bits/stdc++.h>
using namespace std;
void pre_processing(vector<vector<char> > &m , vector<vector<int> > &grid, int n){
    for( int i= 0 ; i< n ;i++ ){
        for( int j = 0 ; j < n ; j++ ){
            cin>>m[i][j];
        }
    }
    for( int i = 1 ;i <= n-2  ; i++ ){
        for( int j = 1 ; j <= n-2 ; j++){
            if( m[i][j]=='.'&&m[i][j-1]=='.'&&m[i][j+1]=='.'&&m[i-1][j]=='.'&&m[i+1][j]=='.')
                grid[i][j] =1;
            else if( m[i][j] == '.')
                grid[i][j] = 0 ;
            else grid[i][j] = -1;
            
        }
    }
    for( int i = 0 ;i < n ;i++ ){
        if( m[0][i]== '*') grid[0][i] = -1;
        else grid[0][i] = 0;
        if( m[n-1][i] == '*' ) grid[n-1][i] = -1;
        else grid[n-1][i] == 0;
        if( m[i][0] == '*') grid[i][0] = -1;
        else grid[i][0] = 0;
        if( m[i][n-1] == '*') grid[i][n-1] = -1;
        else grid[i][n-1] = 0;
    }
}
int main(void){
    int n;
    cin>>n;
    vector<vector<char> > m(n,vector<char> (n));
    vector<vector<int> > grid(n,vector<int> (n) );
    
    pre_processing(m,grid,n);
    
   
    for(  int g  = 1 ; g <= n/2; g++)
    {
        for( int i = g ; i <=n-1-g; i++ )
        {
            for( int j  = g ; j <= n-1-g; j++ ){
                int k= grid[i][j];
                if(grid[i-1][j] >= k && grid[i+1][j]>=k && grid[i][j+1]>= k && grid[i][j-1]>=k)
                    grid[i][j]++;
            }
        }
    }
    int highest= 0;
    for( int i= 0 ;i < n ;i++ )
    {
        for( int j = 0 ; j < n ; j++){
            if( grid[i][j] > highest)
            highest = grid[i][j];
        }
    }
    cout<<highest;
    return 0;
}