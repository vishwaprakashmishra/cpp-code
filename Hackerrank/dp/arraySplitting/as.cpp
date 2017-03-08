#include<bits/stdc++.h>
using namespace std;
int sums(vector<int>&c)
{
    vector<int> left, right;
    long long int leftSum  = 0, rightSum  = 0;
    int i = -1 , j  = c.size(), l, r;
    while ( j > i+1 ){
        if( leftSum < rightSum)
        {
            leftSum += c[++i];
            left.push_back(c[i]);
                       
        }
        else {
            rightSum  += c[--j];
            right.push_back(c[j]);
        }
    }
    if( leftSum != rightSum)
        return 0;
    else {
        l = sums(left);
        r  = sums(right);
        return (max(l,r) + 1);
    }
}
int main(void )
{
    int t, n;
    cin>>t;
    for ( int j = 0 ; j < t; j++ )
    {
        cin>>n;
        bool c = true;
        vector<int> v(n);
    
        for ( int i = 0 ;i <n ; i++ )
        {
            cin>>v[i];
        }
        for ( int i = 0 ;i < n ;i++ )
        {
            if( v[i] != 0 ){
                c = false ;
            }
        }
        if( c == true ){
        cout<< n-1<<endl;
        continue;
        }
        cout<<sums(v)<<endl;
    }
    return 0;
    
}