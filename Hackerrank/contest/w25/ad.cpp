#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class ad{
  public:
    string s, t;
    int k, s_common;
    void in(){
        cin>>s;
        cin>>t;
        cin>>k;
        sol();
    }
    void sol(){
        if( k >= s.size()+ t.size())
        {
            cout<<"Yes"<<endl;
            return ;
        }
        else {
            int sz, i  ;
            (s.size()> t.size())?(sz = t.size()):(sz = s.size());
            for( i =0;i<sz;i++)
                if( s[i] != t[i]) break;
            s_common = i+1;
            int sreplace = s.size() + t.size()-2*s_common;
            if( sreplace > k)
            {
                cout<<"No"<<endl;
                return ;
            }
            else if( (k-sreplace)%2 == 0)
            {
                cout<<"Yes"<<endl;
                return ;
            }
            else {
                cout<<"No"<<endl;
                return;
            }
        }
    }
};
int main(void){
    ad a;
    a.in();
    return 0;
}