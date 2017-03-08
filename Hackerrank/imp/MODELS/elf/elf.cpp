#include<bits/stdc++.h>
using namespace std;
struct bigN{
    
    vector<int> res;
    void inpf(){
        res = vector<int> ();
        res.push_back(1);
    }
    void fact(int n){
        for( int x = 2; x <=n;++x)
            mul(x);
        for( int i =res.size()-1; i >=0; --i)
            cout<<res[i];
    }
    void mul(int x){
        int carry = 0;
        for( int i=0;i<res.size();++i){
            int prod = res[i]*x+carry;
            res[i] = prod%10;
            carry = prod/10;
        }
        while( carry ){
            res.push_back(carry%10);
            carry = carry/10;
        }
    }
};
int main(void){
    int t;
    cin>>t;
    while(t--){
        bigN fa;
        int n;
        cin>>n;
        fa.inpf();
        fa.fact(n);
        cout<<endl;
    }
    return 0;
}