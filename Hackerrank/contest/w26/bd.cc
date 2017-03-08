#include<iostrem>
#include<vector>
#include<cmaath>
#include<algorithm>
using namespace std;
int value(int a){
    int ans ;
    while(a > 0) {
        ans = a%10;
        a = a/10;
    }
}
int main(void){
    int n , sq, sol, max = 0;
    cin>>n;
    sq = floor(sqrt(n))+1;
    vector<int> div();
    for(int i=1;i<sq;i++)
        if( n%i== 0) 
            div.push_back(i);
    for( auto e:div){
        if( value(e) > max ) {
            ans = e; 
            max = value(e);
        }
    }
    cout<<ans<<endl;
    return 0;
}