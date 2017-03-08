#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(void){
    int n ;
    bool finished= false;
    string s;
    cin>>s;
    n  = s.size();
    if( n==1)
    cout<<s<<endl;
    else {
        while( !s.empty() && !finished){
            for(int i=1;i<s.size(),++i){
                if( s[i-1] == s[i] ){
                    s.erase(i-1,2);
                    i--;
                }
            }
            if( n== s.size() || s.size() <=1) finished = true;
            n = s.size();
        }
        if( finished) cout<<s;
    }
    
    return 0;
}