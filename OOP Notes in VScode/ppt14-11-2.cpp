#include<iostream>
using namespace std;

class Complex
{
    int num1, num2;
    public:
    void accept()
    {
        cout << "Enter Complex Numbers: \n";
        cin >> num1 >> num2;
    }
    friend Complex operator+(int r, Complex c);   
    void display()
    {
        cout << num1 << " + "<< num2 << "i" << endl;
    }
};

Complex operator+(int r, Complex c)
{
    Complex sum;
    sum.num1 = r + c.num1;
    sum.num2 = c.num2;
    return sum;
}

int main()
{
    Complex c, sum;
    int i;        
    c.accept();
    cout << "Enter integer: ";
    cin >> i;
    sum = i+c;       
    c.display();
    sum.display();  
    return 0;
}

