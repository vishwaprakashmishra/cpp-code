#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
class so{
  public:
    vector<long long int> s;
    map<long long int , long long int> t;
    long long int n,m;
    void in(){
        cin>>n>>m;
        s = vector<long long int > (m);
        for(int i=0;i<m;i++) cin>>s[i];
        t[n] = 1;
    }
    void sol()
    {
        int noOfMoves =0;
        while(!t.empty()){
            pair<long long int , long long int> e = *(t.begin());
            for(int i =0;i<m;i++){
                
                if( e.first%s[i] == 0){
                   
                long long int g = e.first/s[i];
                if( _check(g))
                    t[g]+=s[i];
                t[e.first]--;
                noOfMoves++;
                if(t[e.first] == 0) t.erase(e.first);
                break;
                }
            }
            
        }
        if( noOfMoves%2 == 0) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
    bool _check(long long int a ){
        bool flag = false;
        for( int i=0;i<s.size();i++){
            if( a%s[i] == 0) flag = true;
        }
        return flag ;
    }
};
int main(void){
    so s;
    s.in();
    s.sol();
    return 0;
}