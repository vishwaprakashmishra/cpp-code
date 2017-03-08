#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void){
    int n;
    string s;
    cin>>n;
    cin>>s;
    vector<char> m;
    if( n==1) cout<<s;
    else {
        for( int i=1;i<s.size(); i++){
            if( s[i] == s[i-1]) m.push(back);
        }
        while(m.size() >0){
            remove(s.begin(), s.end(), m.back());
            m.pop_back();
        }
    } 
    return 0;
}