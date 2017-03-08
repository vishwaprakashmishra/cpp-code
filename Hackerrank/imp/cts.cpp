#include<bits/stdc++.h>
using namespace std;
void cut(vector<int> &a){
    int tmp = a[0];
    for( int i = 0 ;i < a.size(); i++ ){
        a[i] -= tmp;
    }
    while(a[0] == 0 ){
        a.erase(a.begin());
    }
}
int main(void ) 
{
    int n;
    cin>>n;
    vector<int> a(n);
    for( int i =0 ;i < n ;i++ ) 
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    cout<<a.size()<<endl;
    while( a.size() > 0 ) {
        cut(a);
        cout<<a.size()<<endl;
    }
    return 0 ;
}