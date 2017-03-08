#include<bits/stdc++.h>
using namespace std;
struct stree{
    int n, q;
    vector<int> tree;
    vector<int> A;
    void inp(){
        cin>>n>>q;
        A = vector< int > (n);
        tree = vector<int> (3*n);
        fill_n(A.begin(), n, 0);
        build(1, 0,n-1 );
    }
    void build(int node , int start, int end ){
        if( start == end )
            tree[node] = A[start];
        else {
            int mid = (start + end )/2;
            build(node*2, start, mid);
            build(node*2+1, mid+1, end);
            tree[node] = tree[node*2] + tree[node*2+1];
            
        }
    }
    void update(int node, int start, int end , int idx , int val){
        if( start == end ){
            A[start] += val;
            tree[node] += val;
        }
        else {
            int mid = (start+ end )/2;
            if( idx >= start && idx <= mid )
                update(node*2, start, mid, idx , val);
            else 
                update(node*2+1,mid+1, end, idx , val);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }
    int query(int node, int start, int end , int A, int B ){
        if( start > B || end < A )
            return 0;
        if( start >= A && end <= B)
            return tree[node];
        int mid =(start+ end )/2;
        int q1= query(node*2, start,mid , A , B);
        int q2= query(node*2+1, mid+1, end, A , B);
        return (q1+ q2);
    }
};

int main(void){
    stree t;
    t.inp();
    while(t.q--){
        int a, b ;
        string s;
        cin>>s;
        cin>>a>>b;
        if( s[0] == 'a')
            t.update(1,0, t.n-1, a-1, b);
        else 
            cout<<t.query(1,0,t.n-1,a-1,b-1)<<endl;
    }
    return 0;
}