#include<bits/stdc++.h>
using namespace std;

struct  sol{
    string inp;
    stack<char> s;
    map<char, int> pre;
    void conv(){
        cin>>inp;
        stack<char> s;
        string out = "";
        pre['+'] = 0,pre['-'] = 1,pre['*'] = 2,pre['/'] = 3,pre['^'] = 4;
        
        for( auto e:inp){
            if( isChar(e))
                out = out+e;
            else
            {
                if( s.empty() || s.top()== '(')
                    s.push(e);
                else if( e == '('){
                    s.push(e);
                }
                else if( e == ')')
                {
                    while(s.top() !='('){
                        out = out + s.top();
                        s.pop();
                    }
                    s.pop();
                }
                else if( pre[e] > pre[s.top()]) //checkif e< s.top
                    s.push(e);
                else if( pre[e] ==pre[s.top()]){
                    out = out + s.top();
                    s.pop();
                    s.push(e);
                }
                else {
                    while(pre[s.top()]>pre[e]&& !s.empty()){
                    char c = s.top();
                    s.pop();
                    out = out+c;
                    }
                    s.push(e);
                }
            }
        }
        while( !s.empty()){
            out = out + s.top();
            s.pop();
        }
        cout<<out<<endl;
    }
    bool isChar(char e){
        if( (int)e <='z' && (int)e >='a') return true;
        else return false;
    }
};

int main(void){
    int t;
    cin>>t ;
    while (t--){
        sol ip;
        ip.conv() ;        
    }
    return 0;
}