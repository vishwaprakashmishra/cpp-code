#include<bits/stdc++.h>
using namespace std;
struct tree{
    int q;
    unordered_map<int, int > t;
    void inp(){
        int status, no;
        cin>>q;
        for( int i=0;i<q;++i){
            cin>>status>> no;
            if( status==2 ){
                t[no] = 0;
            }
            else {
                if( t[no] == 1){
                    while(t[no] ==1)
                        no++;
                    t[no] = 1;
                }
                else t[no] =1;
                cout<<no<<endl;
            }
        }
    }
};
int main(void){
    tree t;
    t.inp();
    return 0;
}