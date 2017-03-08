#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;
class so{
  public:
    int diff ; 
    string s1 , s2;
    
    void in(){
        cin>>s1;
        cin>>s2;
        diff =0;
    }
    void sol(){
        map<char, int> m1, m2;
        for( int i=0;i<s1.size();++i) m1[s1[i]]++;
        for(int i=0;i<s2.size();++i) m2[s2[i]]++;
        
        for( int i=0;i<26;i++){
            char s = 'a';
            diff = abs(m1[s]-m2[s]);
            s = s+1;
        }
        cout<<diff<<endl;
    }
};
int main(void){
    so a;
    a.in();
    a.sol();
    return 0;
}