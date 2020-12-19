#include <iostream>
#include <conio.h>
using namespace std;

template <class T>
class data
{
 	public:
	        data (T c)
            {
                cout << c << " size = " << sizeof(c) << endl;
            }
};

int main()
{
    data <char> h('A');
    data <int > i(100);
    data <float> j(3.12);
}
