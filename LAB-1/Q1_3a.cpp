#include <iostream>
#include <sstream>
#include <string>
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
    string input;
    stringstream ss;
    cout << "Input a complex number in the form of a+bi and press enter.\n";
    cin >> input;
    ss << input;
    ss >> a.real;
    ss >> a.imag;

    display(a);
}