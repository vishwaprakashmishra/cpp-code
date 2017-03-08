#include<bits/stdc++.h>
using namespace std;

int main(void){
    int r_d,r_m,r_y,d,m,y,diff;
    cin>>d>>m>>y;
    cin>>r_d>>r_m>>r_y;
    
    if( r_y <=y)
        cout<<abs(r-y-y)*10000;
    else if( r_m <=m )
        cout<<abs(m-r_m)*500;
    else if( r_d <=d )
        cout<<abs(d-r_d)*15;
    else
        cout<<"0";
    return 0;
}