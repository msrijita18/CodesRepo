#include <iostream>  
using namespace std;  

class code 
{ 
        private:  int id; 
        public:  
                code ()
                {
                cout << "Default Constructor" << endl;
                }
                code (int a)
                {
                id = a;
                }
                code (code &x)
                {
                id = x.id;
                }
                void display()
                {
                cout << id << endl;
                }
};
int main()
{
    code A(100);
    code B(A);       //copy constructor called
    code C=A;        //copy constructor called
    code D;

    D=A;         //copy constructor  not called

    A.display();
    B.display();
    C.display();
    D.display();

    return 0;
}
