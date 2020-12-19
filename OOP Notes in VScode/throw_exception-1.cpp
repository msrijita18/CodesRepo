#include<iostream>
using namespace std;

void test(int x, double y) throw (int,double)
{
 	if(x==0) 
        throw x;  // int
	//else if (x==0) 
       // throw 'x'; // char
	else if (x==-1.0) 
        throw x; // float
	cout << "End of function block";
}

int main()
{
	try
    {
		test(0,1);
		test(1,0);
		test(1,-1.0);
		test(-1.0,1);   
	}

	
	catch(int m)
	{
	cout<<"Caught an integer\n";
	}
	catch(double d)
	{
	cout<<"Caught a float\n";
	}
	cout<<"End of Try-Catch block\n";
    
	return 0;
}


