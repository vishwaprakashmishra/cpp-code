#include<bits/stdc++.h>
using namespace std;
class inv{
  public:
    int invcnt, n;
    vector<int> a;
    void in(){
        cin>>n;
        a = vector<int> (n);
        for( int i=0;i<n;i++) cin>>a[i];
        invcnt = 0;
        in(0,n-1);       
        cout<<invcnt<<endl;
    }
    void in(int s, int e){
        if( e > s ){
            int m = (s+e)/2;
            in(s, m);
            in(m+1, e);
            mer(s, m , e);
        }
    }
    void mer(int s, int m , int e){
        queue<int> y, z;
        if( e-s == 1){
            if( a[s] > a[e] ){
                invcnt++;
                swap(a[s], a[e]);
            }
        }
        else {
            for( int i=s; i<=m;i++) y.push(a[i]);
            for( int i=m+1;i<=e;i++) z.push(a[i]);
            int k = s ;
            while(!y.empty() && !z.empty()){
                if( y.front() > z.front()){
                    a[k++] = z.front();
                    z.pop();
                    invcnt+= y.size();
                }
                else {
                    a[k++] =y.front();
                    y.pop();
                }
            }
            if( y.empty()){
                while(!z.empty()){
                    a[k++] = z.front();
                    z.pop();
                }
            }
            else {
                while(!y.empty()){
                    a[k++] = y.front();
                    y.pop();
                }
            }
        }
    }
};
int main(void){
    inv m;
    m.in();
    return 0;
}