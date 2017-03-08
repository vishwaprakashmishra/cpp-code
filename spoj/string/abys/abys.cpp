#include<iostream>
#include<sstream>
#include<string> 
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<string > inp(5);
        istringstream iss(s);
        copy(istream_iterator<string>(iss),istream_iterator<string>(),inp.begin());
        for( int i=0;i<5;i+=2){
            try{
                in = stoi(inp[i]);
            }
        }
    }
    return 0;
}