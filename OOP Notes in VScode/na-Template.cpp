#include <iostream>

template<class T, int size> 
class Myfilebuf
{
      T* filepos;
      static int array[size];
public:
      Myfilebuf() { /* ... */ }
      //~Myfilebuf();
      
};


int main()
{
    Myfilebuf<double,200> x;
    return 0;
}