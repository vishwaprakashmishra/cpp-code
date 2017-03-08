#include <bits/stdc++.h>
using namespace std;

int maxSubArr(vector<int> &v){
    int max_till = 0, curr = 0;
    int max = v[0];
    for ( int i = 0 ;i < v.size() ; i++ )
        if( max < v[i] ) 
            max = v[i];
    if( max < 0 ) return max;
    for ( int  i = 0 ; i < v.size() ; i++ ){
        curr  += v[i];
        if ( curr < 0 )
        curr = 0;
        if ( curr > max_till) 
        max_till = curr;
    }
    return max_till;
}
int maxSum(vector<int> &v){
    int sum  = 0, big ;
    for ( int i = 0 ;i < v.size() ; i++ ){
        if( v[i] > 0 )
             sum+= v[i];
    }
    if( sum == 0 ){
        big = v[0];
        for( int i = 0 ;i < v.size(); i++ ){
            if( big < v[i] ) 
                big = v[i];
        }
        return big;
    }
    return sum;
}
int main(void ){
    int t, n;
    cin>>t;
    for ( int i = 0 ; i < t ; i++ ){
        cin>>n;
        vector<int> v(n);
        for ( int j  = 0 ;  j < n ; j++ )
            cin>>v[j];
        cout<<maxSubArr(v)<<" " << maxSum(v)<<endl;
    }
    return 0;
}