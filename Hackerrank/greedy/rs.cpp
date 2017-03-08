#include<iostrem>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;


int main(void){
    string s;
    cin>>s;
    map<char, int> 
    vector<char> v;
    for(int i =0;i<s.size();i++)
        m[s[i]] += 1;
    
    for(auto e:m)
        for( int i = 0;i<e.second/2;i++)
            v.push_back(e.first);
    
    sort(v.begin(), v.end());
    for(auto e:v) cout<<e;
    return 0;
}