#include<iostream>
using namespace std;

void make_pointers(int argv , char *argc[])
{
    for (int i= 1  ; i < argv ; i++ )
        cout<< argc[i]<< " " ;
}
int main(int argv , char * argc[])
{
    cout<< "Making the pointers "<< endl;
    make_pointers(argv, argc);
    return 0;
}