#include <iostream> 
using namespace std; 
  class geeks { 
    int* p; 
 public: 
      geeks() 
    { 
         // allocating memory at run time 
        // and initializing 
        p = new int[3];
    
          for (int i = 0; i < 3; i++) { 
            cout << p[i] << " "; 
        } 
          cout << endl; 
    } 
}; 
  
int main() 
{ 
  
    // five objects will be created 
    // for each object 
    // default constructor would be called 
    // and memory will be allocated 
    // to array dynamically 
    geeks* ptr = new geeks[5]; 
} 
