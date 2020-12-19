#include<iostream>
using namespace std;

class minutes  // sourse class
{
    int m;
    minutes(int ms)
    {
    m=ms;
    }
    void show(){cout << m;}
    void getdata()
    {
        return m;
    }
};

class hours  // destination
{
	int h;
	public:
	hours()
	{
		h=0;
	}
	void show()
	{
	    cout<< "“hour”"<<h<<endl;
	}
	hours (minutes mm)
	{
		h=mm.getdata()/60;
	}
};
int main()
{
    minutes mm(60); hours hr;
    hr=min;
    min.show();
    hr.show();
}



