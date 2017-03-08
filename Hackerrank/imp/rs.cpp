#include<bits/stdc++.h>
using namespace std;
int main(void){
    string s, s2 ;
    int n, no_count = 0, no_count2 = 0, t_c  ;
    cin>>s;
    cin>>n;
    si = s.size();
    int rep = n/si;
    int unique_string = n%si;
    s2 = s.substr(0,unique_string);
    no_count = count(s2.begin(), s2.end(), 'a');
    no_count2 = count(s.begin(), s.end(), 'a');
    t_c  = no_count  + (no_count2*rep);
    cout<<t_c;
    return 0;
}