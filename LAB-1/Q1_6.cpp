#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

struct complex
{
    double real;
    double imag;
};

void Magnitude(complex &a)
{
    double r, i, mag;
    r = a.real * a.real;
    i = a.imag * a.imag;
    mag = sqrt(r + i);
    cout << "Magnitude is " << mag;
}

void Input(string input)
{
    complex a;
    stringstream ss;
    ss << input;
    ss >> a.real;
    ss >> a.imag;
    Magnitude(a);
}

int main()
{
    string input;
    cout << "Input a complex number in the form of a+bi and press enter.\n";
    cin >> input;
    Input(input);
}