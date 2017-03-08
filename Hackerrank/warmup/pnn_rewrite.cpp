#include<bits/c++.h>
using namespace std;

int main(void)
{
    int n;
    float positive = 0.0, negative = 0.0, zeroes = 0.0;
    for ( int i = 0;i <n ;i++ )
    {
        cin>>el;
        if(el > 0)
        positive = positive + 1;
        else if( el < 0)
        negative = negative + 1;
        else 
        zeroes = zeroes + 1;
        
    }
    cout<<positive/n<<endl;
    cout<<negative/n<<endl;
    cout<<zeroes/n;
}