// flatland-space-stations
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n, m;

    cin>>n>>m;
    vector<int> c(m);
    for( int i =0;i<m;i++)
        cin>>c[i];
    sort(c.begin(), c.end());
    int diff = c[0]-0;
    for( int i=1;i<m;i++){
        if( (c[i]-c[i-1])/2 > diff) diff = (c[i]-c[i-1])/2;
    }
    if( diff< n-1-c[m-1]) diff = n-c[m-1];
    cout<<diff;
    return 0;
}