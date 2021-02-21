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
    cout << "The conjugate of the Complex number is (" << a.real << "," << a.imag << ")";
}

void Conjugate(complex &a)
{
    complex ca;
    ca.real = a.real;
    ca.imag = (a.imag) * -1;
    display(ca);
}

void Input(string input)
{
    complex a;
    stringstream ss;
    ss << input;
    ss >> a.real;
    ss >> a.imag;
    Conjugate(a);
}

int main()
{
    string input;
    cout << "Input a complex number in the form of a+bi and press enter.\n";
    cin >> input;
    Input(input);
}