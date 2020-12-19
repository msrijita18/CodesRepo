#include<iostream>
using namespace std;

void divide(int x, int y, int z)
{
	cout << "We are inside function\n";
	if ((x-y)!=0)
	{
        int r=z/(x-y);
        cout << "Result = " << r << endl;
	}
	else
	{
	throw (x-y);
	}
}

int main()
{
    try
    {
        cout<<"We are in try block: \n";
        divide(20,10,30);
        divide(10,10,30);
    }
    catch (int i)
    {
        cout << "Caught Exception at " << i << endl;
    }
    return 0;
}
