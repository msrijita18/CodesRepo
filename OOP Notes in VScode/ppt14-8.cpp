#include <iostream>
using namespace std;

class num
{
	int a,b,c;
	public:
            num(int j, int k, int m)
            {
            	a = j; b = k; c = m;
            }
            void show();
            void operator ++();
}; 

void num::show()
{
    cout << a << b << c << "\n";
}
void num:: operator ++()
{
	a = ++a;
	b = ++b;
	c = ++c;
}
int main()
{
	num obj(2,3,4);
	obj.show();
	++obj;
	obj.show();
	return 0;
}
