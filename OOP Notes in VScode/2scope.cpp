#include <iostream>  

using namespace std; 

class A  
{ 
    public:  
           void fun();     // Only declaration 
};

void A::fun()              // Definition (of function) outside class using :: 
{ 
   cout << "fun() called"; 
} 

int main() 
{ 
   A a;                        // Declaration of class a
   a.fun(); 
   return 0;
}
