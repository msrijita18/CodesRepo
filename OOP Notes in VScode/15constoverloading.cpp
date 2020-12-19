#include <iostream>
using namespace std;

class Rect{
            private: int area;
            public:  Rect()
                    {
                        area = 0;
                    }
                    Rect(int a, int b)
                    {
                            area = a * b;
                    }
                    void display( )
                    {
                        cout << "The area is: " << area << endl;
                    }
};

main( )
{
   Rect r1;
   Rect r2(2, 6);
   r1.display();
   r2.display();
}	


