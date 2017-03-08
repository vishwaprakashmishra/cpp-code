#include<bits/stdc++.h>
using namespace std;
int ORop(vector<vector<int> > &v, int a,int b, int m, vector<int> acc){
    int coun = 0;
    for( int i = 0 ; i < m ;i++ ){
        acc[i] = v[a][i]|v[b][i];
        if( acc[i]== 1) coun += 1;
    }
    return coun;
}
int main(void){
    int n , m, maximum = 0, c= 0;
    cin>>n>>m;
    vector<string> k(n);  
    for(int i = 0 ; i < n ;i++ )
        cin>>k[i];
    
    vector<vector<int> > v(n,vector<int>(m)),count(n,vector<int> (n));   
    vector<int> acc(m);   
    for( int i = 0 ;i < n ; i++ ){
        for(int j = 0 ; j < m ; j++)
            v[i][j] = (int)k[i][j] - '0';
    }
    for( int i = 0 ;i < n; i++ ){
        for( int j  = 0  ; j < n ;j++ ){
            if( i !=j){
                count[i][j] = ORop(v,i,j,m,acc);
                if( count[i][j] > maximum) 
                    maximum = count[i][j];
            }
        }
    }
    for( int i = 0 ; i< n ; i++ ){
        for( int j = 0 ; j < n; j++ ){
            if( count[i][j] == maximum)
                c++;
        }
    }
    cout<<maximum<<endl;
    cout<<c/2;
    return 0;
}
