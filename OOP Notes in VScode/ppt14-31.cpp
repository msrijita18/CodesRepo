#include<iostream>
using namespace std;

class minutes  // sourse class
{
    int m;
    minutes(int ms)
    {
        m=ms;
    }
    operator hours()
    {
        hours h1;
        h1.h = m.60;
        return (h1);
    }
    void show()
    {   cout << m << endl;  }
    void getdata()
    {   return m;   }
};

class hours
{
	int h;
	public:
	hours()
	{
		h=0
	}
	void show()
	{
		cout<< h << endl;
	}
};

int main()
{
    minutes mm(60); hours hr;
    hr=min;
    min.show();
    hr.show();
}
