#include<bits/stdc++.h>
using namespace std;
struct mat{
    int row , col, r;
    vector<vector<int> > v;
    vector<int>  s;
    vector<int> t;
    void inp(){
        cin>>row>>col>>r;
        v = vector<vector<int> > (row, vector<int> (col));
        for( int i=0;i<row;i++){
            for( int j= 0;j<col;j++){
                cin>>v[i][j];
            }
        }
    }
    void rot(int k){
        k = k%s.size();
        t = vector<int> (s.size());
        for( int i =0;i<s.size(); ++i){
            if( i+k <s.size())
                t[i]= s[i+k];
            else 
                t[i] = s[i+k-s.size()];
        }
    }
    void extract(int no){
        s = vector<int> ();
        for( int i=no; i<col-no;i++)
            s.push_back(v[no][i]);
        for( int i=no+1;i<row-no;i++)
            s.push_back(v[i][col-no-1]);
        for( int i = col-no-2;i>=no; --i)
            s.push_back(v[row-no-1][i]);
        if( row-no-2 !=no)
        for( int i= row-no-2;i >no; --i)
            s.push_back(v[i][no]);
    }
    void put(int no){
        int k=0;
        for( int i=no;i<col-no;i++)
            v[no][i] = t[k++];
        for( int i=no+1;i<row-no;i++)
            v[i][col-no-1] = t[k++];
        for( int i=col-no-2; i>=no; --i)
            v[row-no-1][i] = t[k++];
        if( row-no-2 !=no)
        for( int i=row-no-2;i > no;--i)
            v[i][no] = t[k++];
    }
    void sol(){
        for( int i=0;i<min(row,col)/2;++i){
            s = vector<int> ();
            extract(i);
            rot(r);
            put(i);
        }
        for( int i=0;i<row;++i){
            for( int j=0;j<col;++j){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(void){
    mat m;
    m.inp();
    m.sol();
    
    return 0;
}