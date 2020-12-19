#include <iostream> 
using namespace std; 

inline int cube(int s) 
{ 
    return s*s*s; 
} 

inline int Max(int x, int y) 
{
   return (x > y)? x : y;
}


int main() 
{ 
    cout << "The cube of 3 is: " << cube(3) << "\n"; 
    cout << "The cube of 4 is: " << cube(4) << "\n"; 
    cout << "The cube of 5 is: " << cube(5) << "\n"; 

    cout << "Max (20,10): " << Max(20,10) << endl;
    cout << "Max (0,200): " << Max(0,200) << endl;
    cout << "Max (100,1010): " << Max(100,1010) << endl;

    return 0; 
}