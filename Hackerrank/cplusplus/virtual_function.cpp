#include<bits/stdc++.h>
using namespace std;

class Person{
   public:
   string age;
   int age; 
};
class Professor:public Person{
   int publication;
   static int id;
   public:
    Professor(){
        id++;
    }
    void getdata();
    void putdata();
};
Professor::getdata(){
    cin>>name>>age>>publication;
}
Professor::putdata(){
    cout<<name<<" " ;
    cout<<age<<" " ;
    cout<<publication<<" ";
    cout<<id<<end;
}
class Student: public Person{
    int marks[6];
    static int id;
    public:
      Student(){
          id++;
      }
      void getdata();
      void putdata();
};
Student::getdata(){
    cin>>name>>age;
    for( int i = 0 ;i < 6 ; i++ )
    cin>>marks[i];
}
Student::putdata(){
    cout<<name<<" " <<age<<" ";
    int sum = 0;
    for( int i= 0 ;i < 6;i++){
        sum+=marks[i];
    }
    cout<<sum<<" " <<id;
}
int main(void){
    return 0;
}