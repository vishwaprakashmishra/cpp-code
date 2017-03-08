#include<bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    string s; 
    char safe, safe_next;
    int ctr;
    
    cin>>t;
    for( int j = 0 ; j <t ; j++ ){
        cin>>s;
        int i ;
        for(  i = s.size()-1; i > 0 ; i--){
            if( (int)s[i] > (int)s[i-1]){
                if( i != 1)
                    swap(s[i], s[i-1]);
                else{//search next bigger than s[0] 
                  safe = s[0], safe_next =s[1], ctr = 1;
                  for( int i = 1 ; i < s.size(); i++ )
                  {
                      if( (int)s[i] < (int)safe_next && (int)s[i] > (int)safe)
                      {
                          safe_next = s[i];
                          ctr = i;
                      }  
                  }  
                  swap(s[0] , s[ctr]);
                  
                  char *si;
                  int siz = s.size()-1;
                  si = new char[siz];
                  for( int i = 1 ;i < siz+1; i++ ){
                      si[i-1] = s[i];
                  }
                  sort(si,si + siz);
                  s.erase();
                  for( int i = 0  ;i < siz;i++  )
                  {
                      s = s + si[i];
                  }
                  s = safe_next + s;
                }
                break;
            }
        }
        if( i == 0 )
            cout<<"no answer"<<endl;
        else
            cout<<s<<endl;
    }
    return 0;
}