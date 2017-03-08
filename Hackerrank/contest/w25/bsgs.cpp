#include<iostream>
#include<cmath>

using namespace std;
class sol{
  public:
    int a , b , d;
    void in(){
        cin>>a>>b>>d;
        solution();
    }  
    void solution(){
        if( d==0){
            cout<<"0"<<endl;
            return ;
        }
        int ma, mi;
        a>b?(ma = a):(ma = b);
        a>b?(mi = b):(mi= a);        
        float onlyma, onlymi ;
        onlyma = (d*1.0)/ma;
        onlymi = (d*1.0)/mi;
        if( onlyma < 1.0 ){
            if( onlymi == 1){
                cout<<"1"<<endl;
                return ;
            }
            else{ 
                cout<<"2"<<endl;
                return ;
            }
        }
        else if( onlyma == floor(onlyma)) 
        {
            cout<<onlyma<<endl;
            return ;
        }
        else {
            cout<<floor(onlyma)+1<<endl;
            return ;
        }
    }
};
int main(void){
    int q, a, b, d ;
    cin>>q;
    while(q--){
        sol s;
        s.in();
    }
    return 0;
}