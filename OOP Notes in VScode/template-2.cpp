#include <iostream>
#include <iostream>
#include <conio.h>
using namespace std;

template <class T>
void square (T x)
{
    cout << "Square: " << x*x << endl;
} 

int main()
{
    int i; char j; double k;
    cout <<"Enter values for i, j & k :";
    cin >> i >> j >> k;
    square(i);
    square(j);
    square(k);
} 
