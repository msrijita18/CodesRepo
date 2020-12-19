#include <iostream>  
using namespace std;  
class A  
{  
    int a, b;  
    public:  
    int mul(int x,int y)  
    {  
       	a= x ; b= y;
	    int c = a*b; 
        return c;      	
    }     
};  

class B : public A  
{  
    public:  
    void display()  
    {  
        cout << "Multiplication of a and b is : c" << endl;  
    }  
};  
int main()  
{  
   B b; 
   b.mul(5,10); 
   b.display();  
   return 0;  
}  

