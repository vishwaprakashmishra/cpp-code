#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(void){
    int n;
    while(true){
        cin>>n;
        stack<int> s;
        vector<int> in(n);
        if( n != 0){
            vector<int> sol;
            sol = vector<int> ();
            for( int i=0;i<n;i++){
                cin>>in[i];
            }
            int i =0;
            for(;i<n-1;i++)
            {
                if( in[i]>in[i+1])
                    s.push(in[i]);
                else 
                    sol.push_back(in[i]);
            }
            sol.push_back(in[i]);
            while( !s.empty()){
                sol.push_back(s.top());
                s.pop();
            }bool flag = true;
            for( int i=0;i<n-1;i++){
                if( sol[i] > sol[i+1]) flag = false;
            }
            if( flag ) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        else break;
    }
    return 0;
}