#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct complex
{
    double real;
    double imag;
};

void display(complex &a)
{
    cout << "The Sum of the given complex number is (" << a.real << "," << a.imag << ")";
}

void multInverse(complex &a)
{
    complex mia;
    mia.real = a.real / (((a.real) * (a.real)) + ((a.imag) * (a.imag)));
    mia.imag = a.imag / (((a.real) * (a.real)) + ((a.imag) * (a.imag)));
    display(mia);
}

complex Input(string input)
{
    complex a;
    stringstream ss;
    ss << input;
    ss >> a.real;
    ss >> a.imag;
    return a;
}

int main()
{
    string input;
    complex a;
    cout << "Input complex number in the form of a+bi and press enter.\n";
    cin >> input;
    a = Input(input);
    multInverse(a);
}