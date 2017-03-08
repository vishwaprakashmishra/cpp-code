#include <bits/stdc++.h>
using namespace std;
int main(void )
{
    int n;
    cin>>n;
    for ( int j = 0 ; j < n ; j++ )
    {
        for ( int k = n-j-1; k > 0 ; k--)
            cout<<" " ;
        for ( int i = 0 ; i  < j+1;i++ )
        {
            cout<<"#";
        }
        cout<<endl;
    }
    return 0;
}