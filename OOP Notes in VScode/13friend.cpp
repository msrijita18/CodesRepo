#include <iostream>
#include <string>
using namespace std;

class Sample
{
        int a, b;
        public:
                void setvalue()
                {
                    a=25,b=40;
                }
                friend float mean(Sample s);
};

float mean(Sample s)
{
	return float(s.a+s.b)/2.0;
}
//This the friend function
int main()
{
	Sample x;
	x.setvalue();
    cout << "Mean value= "<<mean(x);
    return 0;
}


