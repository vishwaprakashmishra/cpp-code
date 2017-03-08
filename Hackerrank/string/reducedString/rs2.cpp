#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(void){
    int n ;
    string s;
    cin>>s;
    vector<char> ans;
    for( int i=0;i<s.size();i++){
        if( ans.size() >0 && ans.back()==s[i]) 
            ans.pop_back();
        else 
            ans.push_back(s[i]);
    }
    if( ans.size()== 0) cout<<"Empty String"<<endl;
    else 
        for(auto e:ans) cout<<e;
    return 0;
}