#include<bits/stdc++.h>
using namespace std;
void itoArray(int a, vector<int> &v){
    int b=a,len = 0, len2;
    while (b !=0){
        b = b/10;
        len++;
    }
    for( int i = 0  ; i< len; i++ )
        v.push_back(a%int(pow(10,len-i-1)));
}
int main(void){
    int lower_limit, upper_limit;
    cin>>lower_limit>>upper_limit;
    vector<int> orig,sq;
    for( int i = 0 ; i <= upper_limit-lower_limit; i++ ){
        sq[i].push_back(pow(lower_limit+i,2));
        orig[i].push_back(lower_limit+i);
    }
    vector<int> v;
    vector<vector<int> > mat;
    for( int i = 0 ;i < sq.size(); i++ ){
        itoArray(sq[i],v);
        mat.push_back(v);
    }
    for( int i = 0 ;i < mat.size(); i++ ){
        for( int j = 0 ;  j < )
    }
    return 0 ;
}