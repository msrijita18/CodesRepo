#include <iostream>
using namespace std;

int main( )
{ 
    int y=10;
    int &r = y;                         // r is a reference to int y
    cout << r << endl;
    int x = 10; 
    int  &ref = x;                      // ref is a reference to x. 
    ref = 20;                           // Value of x is now changed to 20 
    cout << "x = " << x << endl ;                     
    x = 30; 				            // Value of x is now changed to 30 
    cout << "ref = " << ref << endl ; 

}

