 
#include<iostream> 
#include<fstream> 
#include<string.h> 
#include<iomanip> 
using namespace std;
 
int main() 
{ 
             char name[100],n[100],number[100]; 
 
              ifstream  santo("robin.txt"); 
             cout<<" Enter your desired name to find mobile number :" ; 
              cin>>n; 
 
        again: 
          santo>>name; 
          if(!strcmp(name,n)) 
           { 
                   santo.getline(number,100); 
                   cout<<setw(-20)<<name<<setw(25)<<number<<"\n"; 
 
           } 
         else 
          { 
                if(santo.eof()!=0) 
                cout<<" Sorry your input name is not found in list \n"; 
                 else 
                 goto again; 
          }  
     return 0; 
} 
