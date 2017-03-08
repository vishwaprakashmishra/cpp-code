#include<bits/stdc++.h>
using namespace std;

int main(void )
{
    int n, sumd1 = 0, sumd2 = 0;
    cin>>n;
    vector<vector<int> > v(n);
    for ( int i= 0;i < n;i++)
    for( int j = 0 ; j < n; j++ ){
        cin>>ele;
        v[i].push_back(ele);
    }
    for (int i = 0;i <n ;i++ )
    {
        sumd1 +=v[i][i];
    }
    for ( int  i = 0 , int j = n-1, i <n ;i++, j-- )
    {
        sumd2 +=v[i][j];
    }
    cout<<abs(sumd1 -sumd2);
    return 0;
}