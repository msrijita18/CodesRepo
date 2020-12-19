#include<iostream>
using namespace std;

int main()
{
	int a,b;
	cout << " Enter value for a and b \n";
	cin >> a >> b;
	try
	{
	    if(b!= 0)
		    cout<<a/b;
	    else
		    throw (b);
	} 
    catch(int j)
    {
        cout<< "exception caught:  Divide by Zero\n";
    }
    cout<< "End\n";
}
