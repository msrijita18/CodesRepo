#include <iostream>  
using namespace std;  
class Employee  
 {  
   public:  
            Employee( )    
            {    
                cout<<"Default Constructor Invoked"<<endl;    
            }    
            int id;
            string name;
            float salary;
            Employee(int i, string n, float s)  
            {  
                id = i;  
                name = n;  
                salary = s;  
            }  
            void display()   
            {  
            cout << id << "  " << name << " " << salary << endl;  
            }  
};  

int main(void)   
{  
    Employee e1; 
    Employee e2;   

    Employee e3 =Employee(101, "Sonoo", 890000); 
    Employee e4=Employee(102, "Nakul", 59000); 

    e3.display();  
    e4.display();  

    return 0;  
}  

