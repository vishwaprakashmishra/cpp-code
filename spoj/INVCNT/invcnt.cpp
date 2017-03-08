#include<bits/stdc++.h>

using namespace std;
class swapcount{
  public:
    vector<int> v;
    int n;
    long long int invcnt;
    void inp(){
        ios_base::sync_with_stdio(false);
        cin>>n;
        v = vector<int> (n);
        for(int i=0;i<n;++i) cin>>v[i];
        invcnt =0;
        co(0,n-1);
        cout<<invcnt<<endl;
    }
    void co(int s, int e){
        if( s < e){
            int mid = (e+s)/2;
            co(s, mid);
            co(mid+1, e);
            mer(s, mid , e);
        }
    }
    void mer(int s, int mid , int e){
        queue<int> a, b ;
        int k=s;
        if( s==e)
        return ;
        else {
            for( int i=s;i<=mid;i++) a.push(v[i]);
            for( int i=mid+1;i<=e;i++) b.push(v[i]);
            while(!a.empty() && !b.empty()){
                if(a.front()> b.front()){
                    v[k++] = b.front();
                    b.pop();
                    invcnt = invcnt+a.size();    
                }
                else 
                {
                    v[k++] = a.front();
                    a.pop();
                }
            }
            if(!a.empty()){
                while(!a.empty())
                {
                    v[k++] = a.front();
                    a.pop();
                }
            }
            else{
                while(!b.empty()){
                    v[k++] = b.front();
                    b.pop();
                }
            }
        }
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        swapcount s;
        s.inp();
    }
    return 0;
}