#include <iostream>  
using namespace std; 

class Account {  
public:  
float salary;   
};  

class Programmer: public Account {  
public:  
float bonus;    
};      

int main(void) 
{  
    Programmer p1;  
    p1.salary=60000;   //inherited from base class Account    
    p1.bonus=5000;
    cout << "Salary: " << p1.salary << endl;    
    cout << "Bonus: " << p1.bonus << endl;    
    return 0;  
}  


