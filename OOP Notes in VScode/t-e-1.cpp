#include<iostream>
using namespace std;

int main()
{
    try {
        throw 6;
    }

    catch (int a) {
        cout << "An exception occurred!" << endl;
        cout << "Exception number is: " << a << endl;
    }
}
