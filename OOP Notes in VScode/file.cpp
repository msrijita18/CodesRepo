// constructor function
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char name[30]; float  cost;
 	ofstream outf("ITEM");

	cout << "Enter name: ";
	cin >> name;
	outf << name;                       //write to file item
	cout << "Enter cost: ";
	cin >>cost;
	outf << cost;                        //write to file item
    outf.close();                       // disconnect item file from outf

    ifstream inf("ITEM");             // connect item file to inf
    //inf << name;                         // read name and cost from item
    //inf << cost ;                        // not required
    cout << "Name= "<< name << endl;
    cout<< "Cost= "<< cost << endl;
    inf.close();
    return 0;

}


