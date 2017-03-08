#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class sol{
  public:
    int count ;
    string s, s1, s2;
    void in(){
        cin>>s;
        s1 = s.substr(0, s.size()/2);
        s2 = s.substr(s.size()/2, s.size());
        count = 0;
    }  
    void so(){
        if(s.size()%2 == 1)
        {
            cout<<"-1"<<endl;
            return ;
        }
        map<char, int> m1, m2;
        for( int i=0;i<s1.size();++i)   m1[s[i]]++;
        for(int i=0;i<s2.size();++i)    m2[s2[i]]++;
        for(auto e:m1){
            int di = m1[e.first] -m2[e.first];
            if( di<0) continue;
            else count += di;
        }
        cout<<count<<endl;
    }
};

int main(void){
    int t;
    cin>>t;
    while(t--){
        sol s;
        s.in();
        s.so();
    }
    return 0;
}