#include<iostream>
#include<algorithm>
#include<string>
#include<vector> 
using namespace std;
struct ele{
    int o, c;
    char e;
    ele minusx(ele right){
        ele ans;
        ans.e = '.';
        ans.o =0;
        ans.c =0;
        int d = o-right.c;
        
        if( d > 0)
            ans.o= ans.o+d;
        else if( d< 0)
            ans.c = ans.c-d;
        ans.o = ans.o+right.o;
        ans.c = ans.c+c;
        
        return ans;
    }
};
struct stree{
    int n, q;
    string A;
    vector<ele> tree;
    void inp(){
        cin>>n;
        tree = vector<ele> (3*n);
        cin>>A;
        cin>>q;
        build(1,0 , n-1);
    }
    void build(int node, int start, int end ){
        if( start == end ){
            tree[node].e = A[start] ;
            if( A[start] == '(')
                tree[node].o = 1;
            else tree[node].c = 1;
        }
        else{
        int mid = (start+ end )/2;
        build(node*2, start, mid);
        build(node*2+1, mid+1, end );
        tree[node] = (tree[node*2]).minusx(tree[node*2+1]);
        }
    }
    void update(int node, int start, int end , int idx ){
        if( start == end ){
            if( A[idx ] == '(')
                A[idx] = ')';
            else A[idx ] = '(';
            tree[node].e = A[idx];
            swap(tree[node].o, tree[node].c);
            return ;
        }
        int mid = (start+end)/2;
        if( idx >= start && idx <= mid )
            update(node*2, start, mid , idx );
        else 
            update(node*2+1, mid+1, end, idx );
        // these are the updated things 
        ele a, b , c;
        b = tree[node*2];
        a = tree[node*2+1];
        c = b.minusx(a);
        tree[node] = c;
    }
    int query(){
        if( tree[1].o == 0 && tree[1].c == 0)
            cout<< "YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
};
int main(void){
        stree t;
        t.inp();
        while(t.q--){
            int a;
            cin>>a;
            if( a == 0)
                t.query();
            else 
                t.update(1,0,t.n-1,a-1);
        } 
    
    return 0;
}