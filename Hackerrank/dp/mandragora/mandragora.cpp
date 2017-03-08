#include <bits/stdc++.h>
using namespace std;

int main(void ){
    long long int t  ;
    cin>>t;
    for (int i = 0 ; i < t ;i++ ){
        long long int exp = 0, t_exp = 0;
        long long int tt_su = 0, su = 0, t_s = 1, t_su, N;
        
        cin>>N;
        vector<int> H(N);
        for(int j =  0 ;  j < N ; j++ ){
            cin>>H[j];
            su += H[j];
        }
        sort(H.begin(), H.begin() + H.size());
        t_su = su;
        
        //ans starts here
        if( N == 1 )
        {
            cout<<H[0]<<endl;
            continue;
        }
        for(int k = 0 ; k < N ; k++ ){
            tt_su += H[k];   
            t_exp = (k+2)*(su - tt_su);
            if( t_exp > exp )
                exp  = t_exp ;
         
        }
        cout<<exp<<endl; 
        // ans ends here
    }
    return 0;
}