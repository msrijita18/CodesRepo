#include <iostream>  
using namespace std;  
class B
{  
    int a;  
    public: 
    int b; 
    void get_ab()
    {
        cout << "Enter a and b:";
        cin >> a >> b;
    }
    int get_a()
    {
        return a;
    }
    void show_a()
    {
        cout << "a = " << a << endl;
    }  
};  

class D : public B 
{  
    int c;
    public:  
    void mul()  
    {  
         get_ab();
         c= b*get_a();
    }  
    void display()
    {
        show_a();
        cout << b;
        cout << "Multiplication of a and b is : "<< c << endl; 
    }
};  
int main()  
{  
   D d;
   d.get_ab();      //
   //d.mul();
   //d.show_a();      //
   //d.display();
   //d.b = 20;        //
   //d.mul();
   //d.display();
   return 0;  
}  

