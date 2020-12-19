#include<iostream> 
using namespace std; 
  
class Test 
{ 
   int x; 
public: 
    virtual void show() = 0; 
    int getX() 
    { 
        return x; 
    } 
}; 
  int main(void) 
{ 
    //Test t;  
    Test *t; 
    //Compiler Error: 
    //cannot declare variable 't' to be of abstract type 
    //'Test' because the following virtual functions are pure 

    return 0; 
} 
