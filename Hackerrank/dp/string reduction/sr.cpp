#include<bits/stdc++.h>
using namespace std;
string let(string s1, string s2){
    if( s1 == "a" || s2 == "b" )
        return "c" ;
    else if( s1 == "a" || s2 == "c")
        return "b" ;
    else if( s1 == "b" || s2 == "c")
        return "a";
    else if ( s1 == "b" || s2 == "a")
        return "c";
    else if ( s1 == "c" || s2 == "a"  )
        return "b";
    else if ( s1 == "c" || s2 == "b"  )
        return "a";
    else 
        return s1+s2;
}
int main(void ){
    int t ;
    cin>>t ;
    string s, s1, s2 , s3;
    for ( int i = 1 ; i <= t ; i++ ){
        cin>>s;
        for ( int j = 0 ; j < s.length()-1 ; )
        {
            s1 = s.substr(j,1);
            s2 = s.substr(j+1,1);
            s3 = let(s1, s2);
            if( s1 == s2)
            {
                j++ ;
            }
            else 
            {
                s.replace(i,2,s3);
            }
        }
        cout<<s.length();
        cout<<endl;
    }
    return 0;
}