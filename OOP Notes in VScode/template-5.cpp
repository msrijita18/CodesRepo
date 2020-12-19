#include <iostream>
#include <conio.h>
using namespace std;

template <class T1,class T2>
class data
{
    public:
    void show(T1 a,T2 b)
    {
    cout << "a = " << a << " and " << "b = " << b << endl;
    }
};

int main()
{
    int i[]={1,2,3};
    float f[]={3.1,5.8,2.5};
    data <int, float> h;
    for (int m=0; m<3; m++)
    {
        h.show(i[m],f[m]);
    }
    return 0;
} 

