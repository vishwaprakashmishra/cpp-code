#incldue <bits/stdc++.h>
using namespace std;

int main(void){
    int t, N, K ;
    cin>>t;
    for( int i = 0 ;i < t ;i++)
    {
        cin>>N>>K;
        int count = 0, a;
        for( int j = 0 ; j < N ; j++ )
        {
            cin>>a;
            if( a[j] <= 0 ) count++ ;
        }
        if( count >= K ) cout<<"NO"<<endl;
        else cout<< "YES" <<endl;
    }
    return 0 ;
}