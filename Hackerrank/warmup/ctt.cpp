#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    int alice = 0, bob= 0;
    vector<int> a(3),b(3);
    cin>>a[0]>>a[1]>>a[2];
    cin>>b[0]>>b[1]>>b[2];
    for ( int i = 0 ; i <3 ; i++ )
    {
        if( a[i] > b[i] ) 
            alice++;
        else if( a[i] == b[i] )
            continue;
        else 
            bob++;
            
    }    
    cout<<alice<<" " << bob;
    return 0;
}