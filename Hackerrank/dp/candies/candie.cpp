#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v,vector<int> &s, int u1, int v1, int u2 , int v2){
    if(( (v1-u1)==0)&&((v2-u2)== 0)){
        if( v[v1] > v[u2])
            s[v1]++;
        else if( v[v1] < v[u2])
            s[u2]++ ;
    }
    else if ( (s[v1] <= s[u2])&&(v[v1]>v[u2])){
        int d = s[u2] - s[v1], i;
        for( i = v1 ; (s[i-1] > s[i])&&(i >=u1) ; i--){}
        int j = v1;
        s[j--] += ( d + 1);
        for(  ; j >= i ; j-- )
            if( s[j] < s[j+1]+1)
                s[j] = s[j+1] +1; 
    }
    else if( ( s[v1] >= s[u2]) && ( v[v1] < v[u2])){
        int d = s[v1] - s[u2], i;
        for ( i = u2 ; (s[i+1] > s[i])&&(i <= v2) ; i++ ){}
        int j = u2;
        s[j++] += (d + 1);
        for ( int j = u2 ;j <= i ; j++ )
            if( s[j] < s[j-1]+1)
                s[j] = s[j-1] + 1;
    }
}

void sol ( vector<int> &v, vector<int> &s, int st, int en){
    
    if(( en - st ) == 0 )
        s[st] = 1;
    else{
        int mid = ( en - st)/2;
        sol( v,s, st,st + mid);
        sol( v,s, st + mid + 1, en);
        merge(v,s, st, st+mid, st+mid+1, en);
    }
}

int main(void ){
    int N;
    cin>>N;
    vector<int> v(N);
    
    for( int i  = 0  ; i<N ; i++ ){
        cin>>v[i];
    }
    vector<int> s(N);
    int sum= 0;
    sol(v,s,0,N-1);
    for( int i = 0 ; i < N ; i++ )
        sum += s[i];
    cout<<sum;
    return 0;
}