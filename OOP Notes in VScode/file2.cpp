#include <iostream>
#include <fstream>
using namespace std;

void main()
{
  char c,fn[10];
  cout<<"Enter the file name....:";
  cin>>fn;
  ifstream in(fn);
  if(!in)
  {
    cout<<"Error! File Does not Exist";
    
    return;
  }
  cout<<endl<<endl;
  while(in.eof()==0)
  {
    in.get(c);
    cout<<c;
  }

}