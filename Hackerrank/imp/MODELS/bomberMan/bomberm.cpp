#include<bits/stdc++.h>
using namespace std;
struct mat{
    int r, c, n;
    vector<string> s1;
    vector<string> s2;
    vector<string> s3;
    void inp(){
        cin>>r>>c>>n;
        s1 = vector<string> (r);
        s2 = vector<string > (r);
        s2 = vector<string> (r);
        for( int i=0;i<r;i++){
            cin>>s1[i];
            s2[i]=s1[i];
        }
    }
    void change(int y, int x){
        if(x-1>=0 ) s2[y][x-1] = 'O';
        if(x+1< c) s2[y][x+1] = 'O';
        if(y-1>=0) s2[y-1][x] = 'O';
        if(y+1< r) s2[y+1][x] = 'O';
    }
    void change3(int y, int x){
        if(x-1>=0 ) s3[y][x-1] = 'O';
        if(x+1< c) s3[y][x+1] = 'O';
        if(y-1>=0) s3[y-1][x] = 'O';
        if(y+1< r) s3[y+1][x] = 'O';
    }
    void make2(){
        for( int i=0;i<r;++i)
        for( int j=0;j<c;++j)
            if( s1[i][j] == 'O') 
                change(i,j);
        
        for( int i=0;i<r;++i){
            for( int j=0;j<c;++j){
                if(s2[i][j] =='O') s2[i][j] ='.';
                else s2[i][j] = 'O';
            }
        }
    }
    void make3(){
        for( int i=0;i<r;++i)
        for( int j=0;j<c;++j)
            if( s2[i][j] == 'O') 
                change3(i,j);
        
        for( int i=0;i<r;++i){
            for( int j=0;j<c;++j){
                if(s3[i][j] =='O') s3[i][j] ='.';
                else s3[i][j] = 'O';
            }
        }
    }
    void sol(){
        make2();
        if( n > 3){
            s3 = s2;
            make3();
        }
        if( n==0 || n==1){
            for( int i=0;i<r;++i) cout<<s1[i]<<endl;
        }
        else if( n==3) {
            for( int i=0;i<r;++i) cout<<s2[i]<<endl;
        }
        else if( n%2 == 0) 
        {
            for( int i=0;i<r;++i){
                for( int j=0;j<c;++j){
                    cout<<'O';
                }
                cout<<endl;
            }
        }
        else if( n%2==1 ){
            if( ((n-1)/2)%2 == 1)
                for( int i=0;i<r;++i) cout<<s2[i]<<endl;
            else 
                for( int i=0;i<r;++i) cout<<s3[i]<<endl;
        }
    }    
};
int main(void){
    mat m;
    m.inp();
    m.sol();
    return 0;
}