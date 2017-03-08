#include<bits/stdc++.h>
using namespace std;
int _rev(int a){
    int dig=0, sol = 0,tem  = a;
    while(tem > 0) {
        tem = tem/10;
        dig++;
    }
    queue<int> q;
    for( int i=0;i<dig;i++){
        int b = a%10;
        a = a/10;
        q.push(b);
    }
    for( int i=dig-1;i>=0;--i){
       int a =  q.front();
       sol += a*pow(10, i);
       q.pop();
    }
    return sol;
}
int main(void){
    int a, b , k , count = 0;
    cin>>a>>b >>k;
    
    for( int i= a;i <=b ;i++)
    {
        int rev = _rev(i);
        if( abs(rev-i)%k == 0) 
            count++;
    }
    cout<<count <<endl;
    return 0;
}