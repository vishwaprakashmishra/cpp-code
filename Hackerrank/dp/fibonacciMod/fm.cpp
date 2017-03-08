#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
class bn{
  public:
    vector<int> no;
    int n; 
    bn(){
        no = vector<int> (1);
        no[0] =0;
        n =0;
    }
    void operator=(ll a){
        no[0] = a%10;
        a = a/10;
        n++;
        while(a > 0){
            no.push_back(a%10);
            a = a/10;
            n++;
        }   
    }
    bn add( bn b){
        bn c ;
        int k = 0, r =0;
        while(n >k && b.n > k){ // adding array until both 
            c.no.push_back((no[k]+b.no[k]+r)%10);
            r = (no[k]+b.no[k]+r )/10;// both are of same 
            c.n++;  // size 
            k++;
        }
        
        if( n > k ){ /// addding leftovers from a 
            while( n > k ){
                c.no.push_back((no[k]+r)%10);
                r = (no[k]+r)/10;
                k++;
                c.n++;
            }
        }
        if( b.n >k){    // adding leftovers from b 
            while( b.n >k ){
                c.no.push_back((b.no[k]+r)%10);
                r = (b.no[k]+r)/10;
                c.n++;
                k++;
            }
        }
        if( r > 0) c.no.push_back(r); // adding remainder if 
        return c;
    }// any left 
    bn mul( bn b ){
        bn c ;
        int i , j , r=0;
        // matrix b.n x b.n+n+1 
        vector<vector<int> > m (b.n, vector<int> (b.n+n+1));
        for( i=0;i<b.n;i++) 
            fill_n(m[i].begin(), b.n+n+1, 0);
        for(  i =0;i<b.n;i++){
            r = 0;
            for( j = i ;j < i+n;i++){
                m[i][j] = (b.no[i]*no[j-i] + r )%10;
                r = (b.no[i]*no[j-i] + r )/10;
            }
            if( r > 0)
                m[i][j] = r;
        }
        for( i=0;i<n+b.n+1;i++){
            ll add =0;
            for( j =0;j<b.n;j++){
                add += m[j][i];
            }
            c.no.push_back((add+r )%10);
            r = (add+r )/10;
            c.n++;
        }
        if( r > 0) {
            c.n++;
            c.no.push_back(r);
        }
        else if ( c.no[c.n-1] ==0){
            c.n--; 
            c.no.pop_back();
        }
        return c; 
    }
};
int main(void){
    int t1, t2, n;
    cin>>t1>>t2>>n;
    if( n <= 10)
    {
        bn ans, temp , first, sec;
        first = t2;
        sec = t1;
        for( int i =2;i<=n;i++){
            temp = first ;
            bn k = first.mul(first);
            first = sec.add(k);
            ans  = first ;
            sec = temp;
        }
        for(ll i=first.n-1;i>=0;i--)
            cout<<first.no[i];
    }
    return 0;
}