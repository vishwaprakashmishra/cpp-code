#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, positive = 0, negative = 0;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    for(int i = 0;i < n;i++ ){
        if(arr[i] > 0)
            positive++;
        else if( arr[i] <0 )
            negative++;
    }
    float p , ne, neu;
    p = positive/(1.0*n);
    cout<<p<<endl;
    ne = negative/(1.0*n);
    cout<<ne<<endl;
    neu = (n -(positive+negative))/(1.0*n);
    cout<<neu;
    return 0;
}
