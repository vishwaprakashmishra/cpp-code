#include<bits/stdc++.h>
using namespace std;
int main(void )
{
    int hours;
    string t, s1, hours2,real_time;
    cin>>t;
    s1 = t.substr(8,2);
    if( s1 == "PM") 
    {
        s1 = t.substr(0,2);
        hours  = stoi(s1);
        if( hours == 12)
        {
            cout<< t.substr(0,8);
        }
        else {
        hours= hours + 12;
        hours2 = to_string(hours);
    
        real_time = hours2 + t.substr(2,6);
        cout<<real_time;
        }
    }
    else 
    {
        s1 = t.substr(0,2);
        if(stoi(s1) == 12)
        {
            t.replace(0,2,"00");
            cout<<t.substr(0,8);
        }
        else
            cout<<t.substr(0,8);
    }    
    return 0;
}