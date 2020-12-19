#include <iostream>
#include <conio.h>
using namespace std;

template <class T1,class T2>
class data
{
    public:
            data(T1 a,T2 b)
            {
            cout << "a = " << a << " and " << "b = " << b << endl;
            }
};

int main()
{
    data <int, float> h(2,2.5);
    data <int, char> i(15,'c');
    data <float, int> j(3.12,50);
} 

