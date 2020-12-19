#include <iostream>

using namespace std;

int main () 
{  

   	int intvar=25;
	float floatvar=35.87;
	cout<<"intvar= " <<intvar << endl;
	cout<<"floatvar= " <<floatvar << endl;
	cout<<"float(intvar)= " <<float(intvar) << endl;
	cout<<"int(floatvar)= " <<int(floatvar) << endl; 

    double a = 21.09399;
    float b = 10.20;
    int c ;
    c = (int) a;
    cout << "Line 1 - Value of (int)a is :" <<  c  << endl ;
    c = (int) b;
    cout << "Line 2 - Value of (int)b is  :" <<  c  << endl ;
    
    return 0;
}
