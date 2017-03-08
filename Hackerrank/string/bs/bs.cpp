#include<iostream>
#include<string>
#include<vector>
using namespace std;
class st{
    public:
    int n;
    string s;
    string pat;
    int out ;
    void in(){
        cin>>n;
        cin>>s;
        pat = "010";
        out = 0;
        match();
    }
    void match(){
        if( n<3) return ;
        for( int i=0;i<n-2;i++){
            
            if(s[i] == pat[0])
            {    
                if( _match(i)) {
                    i = i+2;
                    s[i] = '1';
                    out++;                
                }
            }
        }
        cout<<out<<endl;
    }
    bool _match(int i){
        for( int j =i;j<pat.size();j++, i++)
            if( s[i] != pat[j]) return false ;
        return true;
    }
};
int main(void){
    st s;
    s.in();
    return 0;
}