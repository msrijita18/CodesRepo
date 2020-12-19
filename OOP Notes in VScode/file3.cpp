#include <iostream>
#include <fstream>
using namespace std;

void main()
{
    ofstream fileo("Filethree");
    fileo<<"Hello GS";
    fileo.close();
    ifstream fin("Filethree");
    char ch;
    while(fin)
    {
    fin.get(ch);
    cout<<ch;
    }
    fin.close();
}