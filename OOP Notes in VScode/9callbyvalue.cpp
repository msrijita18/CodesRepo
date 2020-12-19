#include <iostream>
using namespace std;   

void  swap(int , int );

int  main()
{
   int a=10,b=20;
   swap(a,b);
   cout<<a<<" "<< b;
   return 0; 
}

void  swap(int c, int d)
{
   int temp;
   temp=c;
   c=d;
   d=temp;
   cout<< "After swap:"<<c <<" "<<d << endl; 
}
