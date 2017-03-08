#include<bits/stdc++.h>
using namespace std;
int _rev(int a) {
    int dig =0,sol =0,  reA = a;
    while( reA >0) {
        reA = reA/10;
        dig++;
    }
    queue<int> q;
    
    for( int i = 0 ;i < dig ; i++){
        q.push(a%10);
        a = a/10;    
    }
    for( int i =dig-1;i>=0;i--){
        sol  += q.front()*pow(10, i);
        q.pop();
    }
    return sol;
}
int main(void){
    int  n, x, y; 
    cin>>n;
    for( int i=0;i<n;i++){
        cin>>x>>y;
        int z = _rev(x) + _rev(y);
        cout<<_rev(z)<<endl;
    }
    return 0;
}