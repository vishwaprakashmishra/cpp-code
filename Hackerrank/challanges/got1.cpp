#include<bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    map<char,int> m;
    for( int i=0;i<s.size();++i)
    {
        ++m[s[i]];
    }
    for( auto e:m){
        if( e%2==1) odd_present++;
    }
    if( s.size()%2==0 && odd_present>0) 
    cout<<"NO"<<endl;
    else if( s.size()%2==1 && odd_present==1)
    cout<<"YES"<<endl;
    else if( odd_present==0)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}