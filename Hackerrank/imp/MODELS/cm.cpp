#include<bits/stdc++.h>
using namespace std;
void input(vector<string> &cm, vector<string> &ans_map, int n){
    for( int  i = 0 ; i < n ;i++ )
        cin>>cm[i];
}
void pro(vector<string> &cm, vector<string> &ans_map, int n){
    ans_map[0] = cm[0];
    ans_map[n-1] = cm[n-1];
    for( int i = 1 ;i < n-1; i++ ){
        ans_map[i] = cm[i][0];
        for( int j = 1 ; j < n-1 ; j++ ){
            if( (int)cm[i][j] > (int)cm[i-1][j]&& (int)cm[i][j]>(int)cm[i+1][j]&& (int)cm[i][j]>(int)cm[i][j-1] && (int)cm[i][j] > (int)cm[i][j+1])
                ans_map[i] += 'X';
            else
                ans_map[i] += cm[i][j];
        }
        ans_map[i] += cm[i][n-1];
    }
}
int main(void){
    int n;
    cin>>n;
    vector<string> cm(n), ans_map(n);
    
    input(cm,ans_map,n);
    pro(cm,ans_map,n);
    
    for( int i =0 ;i < n ; i++ )
        cout<<ans_map[i]<<endl;
    
    return 0;
}