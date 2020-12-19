#include <iostream> 
#include <istream> 
#include <sstream>
#include <string>      
#include <iomanip>   

using namespace std; 

int main()  
{ 
    istringstream str("           Programmer");   // Ignore all the whitespace in string 
    string line; 
    getline(str >> std::ws, line);              // str before the first word. 
    
    cout << line << endl; 
    // without flush, the output will be the same. 
    cout << "only a test" << flush; 
    // Use of ends Manipulator 
    
    cout << "\na"; 
      // NULL character will be added in the Output 
    cout << "b" << ends; //space
    cout << "c" << endl; //new line

    cout << setw(10);  
    cout << 24 << endl;  
    
     int  a,b;  
    a = 200;  
    b = 300;  
    cout << setw (5) << a << setw (5) << b << endl;  
    cout << setw (6) << a << setw (6) << b << endl;  
    cout << setw (7) << a << setw (7) << b << endl;  
    cout << setw (8) << a << setw (8) << b << endl;  

    cout << setfill ('x') << setw (10);  
    cout << 24 << endl;  

    double f =3.14159;  
    cout << setprecision(5) << f << '\n';  
    cout << setprecision(9) << f << '\n';  
    cout << fixed;  
    cout << setprecision(5) << f << '\n';  
    cout << setprecision(9) << f << '\n';  

    return 0; 
} 


