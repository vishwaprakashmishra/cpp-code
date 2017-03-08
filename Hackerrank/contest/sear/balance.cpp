#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    string s;
   while(t--){
       cin>>s;
       int balanced = 0;
       bool flag = true;
        stack<char> m;
       for(auto e:s){
           if( e == '('){
               m.push(e);
           }else if( e == ')'){
               if( m.size() !=0 && m.top() == '(') 
               {
                   m.pop();
                   balanced+=2;
               }
               else{ 
                   flag = false;
                   break;
               }
           }
       }
       cout<<balanced<<endl;
   }
    return 0;
}