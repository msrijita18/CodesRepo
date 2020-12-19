#include<iostream> 
using namespace std; 
class Base 
{ 
public: 
    virtual void show() = 0; 
}; 
  
class Derived : public Base 
{

}; 
  
int main(void) 
{ 
  //Derived d;
  //Compiler Error: cannot declare variable 'd' to be of 
  //abstract type 'Derived'  because the following virtual 
  //functions are pure within 'Derived': virtual void Base::show() 
  return 0; 
}
