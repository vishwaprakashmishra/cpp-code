#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n , count = 0 ;
    cin>>n;
    vector<int> c(n);
    for( int i = 0 ;i < n ; i++ ){
        cin>>c[i];
    }
    for( int i = 0 ; ;  )
    {
        if( i== n-1) break;
        else if(  i == n-2) {
            count++;
            i++;
        }
        else if( c[i+2] == 0 ){
            i = i+2;
            count++;
        }
        else if ( c[i+1] == 0)
        {
            i++;
            count++;
        }
        
    }
    cout<<count<<endl;
    return 0;
}