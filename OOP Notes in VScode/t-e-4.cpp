#include<iostream>
using namespace std;

void test(int x)
{
 	try
    {
	if(x==1) throw x;  // int
	else if (x==0) throw 'x'; // char
	else if (x==-1) throw 1.0; // float
    //else
	cout << "End of try block\n";
	}
	catch(char c)
	{
	cout << "Caught an Character \n";
	}

	catch(int m)
	{
	cout << "Caught an integer \n";
	}
	catch(double d)
	{
	cout << "Caught a float \n";
	}
	cout << "End of Try-Catch block\n";
}

int main()
{
    test(1);
    test(0);
    test(-1);
    test(2);  
}
