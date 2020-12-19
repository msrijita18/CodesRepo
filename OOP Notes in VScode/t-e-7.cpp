#include<iostream>
using namespace std;
void test(int x) throw (int)
{
 	if(x==1) throw x;  // int
	else if (x==0) throw 'x'; // char
	else if (x==-1) throw 1.0; // float
	cout << "“End of function block”";
}
int main(){
	try{
		test(0);
		test(1);
		test(-1);
		test(2);   
	}

	catch(char c)
	{
	cout<<"”Caught an character \n”";
	}
	catch(int m)
	{
	cout<<"”Caught an integer \n”";
	}
	catch(double d)
	{
	cout<<"”Caught a float \n”";
	}
	cout<<"”End of Try -Catch block”";
	return 0;
}



