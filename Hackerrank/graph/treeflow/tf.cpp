#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class graph {
    int n ;
    vector<vector<pair<int, int> > > g;
    void in(){
        cin>>n;
        g = vector<vector<pair<int, int> > > (n, vector<pair<int, int> > ());
        for(int i=0;i<n-1;i++){
            cin>>x>>y>>w;
            g[x].push_back()
        }
    }  
};