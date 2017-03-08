#include<bits/stdc++.h>
using namespace std;
struct Lady{
    int n;
    string b;
    void inpb(){
        cin>>n;
        cin>>b;
    }
    bool basesol(){
        if( n == 1) return true;
        else if( n== 2 && b[0] == b[1] ) return false;
        else if(n==2 && b[0]!=b[1])return true; 
        else {
            for(int i =0;i<n;++i){
                if( i-1>0 && b[i] == b[i-1]) continue;
                else if( i+1 <n && b[i] == b[i+1] ) i++;
                else return true;
            }
            return false;
        }
    }
    void sol(){
        bool sad = false;
        map<char, int> board;
        for( int i=0;i<n;i++)
            board[b[i]]++;
        if( board['_']== 0)
            sad = basesol();
        else{
            for( auto e:board){
                if( e.first == '_') continue;
                else if( e.second >=2) continue;
                else if( e.second < 2) sad = true;
            }
        }
        if( sad ) cout<<"NO"<<endl;
        else cout<< "YES"<<endl;          
    }
};
int main(void){
    int g, n;
    string b;
    cin>>g;
    while(g--){
        Lady b;
        b.inpb();
        b.sol();
    }
    return 0;
}