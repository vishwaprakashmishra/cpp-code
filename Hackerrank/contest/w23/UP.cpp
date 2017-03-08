#include<bits/stdc++.h>
using namespace std;

void LPSArray(string str, int M, vector<int> &lps){
    int len = 0 ;
    int i = 1;
    lps[0] = 0;
    while(i < M){
        if( str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if( len != 0)
                len = lps[len-1];
            else 
                lps[i++] = 0;
        }
    }
}
int si(string str){
    int n = str.size(), coun = 0;
    vector<int> lps[n];
    LPSArray(str, n, lps);
    int len = lps[n-1];
    return (len>0 && n%(n-len) == 0)? n-len: n;
}
int main(void){
    string s;
    int m, siz;
    cin>>s;
    cin>>m;
    siz = si(s);
    cout<< (m/siz)%(1000000007);
    return 0;
}