#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class graph {
  public:
    vector<vector<int, int > > g ;
    int n1, n2, d;
    void inp(){
        cin>>n1>>n2>>d;
        g = vector<vector<pair<int, int> > > (n1+n2+1,vector<pair<int,int> > ());
        for( int i =0;i<d;i++)
        {
            cin>>x>>y;
            
        }
    }    
};

int main(void){
    return 0;
}