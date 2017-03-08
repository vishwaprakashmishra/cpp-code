#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int s, t, a, b  ,m , n;
    cin>>s>>t;
    cin>>a>>b;
    cin>>m>>n;
    vector<int> apples(m);
    vector<int> oranges(n);
    for(int i=0;i<m;++i)    cin>>apples[i];
    for( int i=0;i<n;i++)   cin>>oranges[i];
    int apple = 0;
    int orange =  0;
    for( int i=0;i<m;++i)
        if( ( (apples[i]+a) >= s) && ((apples[i]+a) <=t) )  apple++;
    for( int i=0;i<n;++i)
        if( ((oranges[i]+b) <=t) && ((oranges[i]+b) >=s))   orange++;
    return 0;
}