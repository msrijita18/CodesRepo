#include<iostream>
using namespace std;

class complex
{
	float real, imag;
	public:
	complex()
    {
	    real=imag=0;
	}
	complex (float r, float i)
	{
        real = r;
        imag = i;
	}
    friend void add operator -(complex c)
    {
        c.real = -c.real;
        c.imag = -c.imag;
        return c;
    }
    void display()
    {
        cout << real << " " << imag << endl;
    }
};
int main()
{
	complex c1(1.5, 2.5), c2;
	c1.display();
	c2 = -c1;
	c2.display();
    return 0;
}



