#include<iostream>
using namespace std;

class number
{
	int x, y;
	public:
    number()
    {
        x = 0;
        y = 0;
    }
	number(int j, int k)
    {
	    x = j; 
        y = k;
	}
	number operator +(number T)
	{
        T.x = x + T.x;
        T.y = y + T.y;
        return T;
	}

    void show()
    {
        cout << "x = " << x << " y = " << y << endl;
    }
};

int main()
{
    number A(2,3), B(4,5);
    A.show();
    B.show();
    number C=A+B; // = (2+B.4 , 3+B.5)
    C.show();	
}
