#include <iostream>
using namespace std;

struct complex
{
    double real;
    double imag;
};

void display(complex a)
{
    cout << "Your result is (" << a.real << "," << a.imag << ")";
}

int main()
{
    complex a;
    a.real = 3.0623;
    a.imag = 5.879;
    display(a);
}