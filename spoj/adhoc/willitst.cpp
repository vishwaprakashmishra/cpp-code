#include<iostream>
using namespace std;
int main(void){
    int n; 
    int loop =0;
    while( n>1){
        if(n%2==0) 
            n = n/2;
        else 
            n = n*3 + 3;
        if (loop > 100000000) break;
        else loop++;
    }
    if( loop >= 100000000) cout<<"NIE"<<endl;
    else cout<<"TAK"<<endl;
    return 0;
}