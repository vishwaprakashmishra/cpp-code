#include<bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int row, col ;
    row = floor(pow(s.size(), 0.5));
    col = ceil(pow(s.size(), 0.5));
    for( int i=0;i<col ;i++){
        for( int j=0;j < row;j++){
            if( j*col+i < s.size())
            cout<<s[j*col+i];
        }
        cout<<" ";
    }
    return 0;
}