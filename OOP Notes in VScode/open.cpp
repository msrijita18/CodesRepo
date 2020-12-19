// open() function
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char name[30]; float cost;
 	ofstream outf ;                 // connect item file
	outf.open("ITEM");

	cout << "Enter item name: ";
	cin >> name;
	outf << name;                    //write to file item

	cout << "Enter cost: ";
	cin >> cost;
	outf << cost;                    //write to file item

    outf.close();                   // disconnect item file from outf

    ifstream inf;
    inf.open("ITEM");               // connect item file to inf

    cout << "Name= " << name << endl;
    cout << "Cost= " << cost << endl;

    inf.close();
    return 0;
}


