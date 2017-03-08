#include<iostream>
#include<string>
#include<ctype>
using namespace std;
int main(void){
    string s;
    int count =1;
    cin>>s;
    for( int i=0;i<s.size();i++)
        if( isupper(s[i])) count++;
    cout<<count;
    return 0;
}