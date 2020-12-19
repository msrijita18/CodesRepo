#include<iostream>
using namespace std;

void divide(double x, double y)
{
	cout << "Inside function\n";
	try
	{
		if (y==0.0) throw y;
		else 
		cout << "Division = " << x/y << endl;
	} 
	catch(double )
	{
		cout << "Caught Double inside fun\n";
		throw; 
	}
	cout << "End of Functon\n";
}

int main()
{
	cout << "Inside main function\n";
	try{
		divide(10.5, 2.0);
		divide(20.0, 0.0);
	}
	catch(double)
	{
		cout << "Caught double inside main\n";
	}
	cout<<"End of main\n";
	return 0;
}
