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
    cout << "Your result is (" << a.real << "," << a.imag << ")";
}

void Input(string input)
{
    complex a;
    stringstream ss;
    ss << input;
    ss >> a.real;
    ss >> a.imag;
    display(a);
}

int main()
{
    string input;
    cout << "Input a complex number in the form of a+bi and press enter.\n";
    cin >> input;
    Input(input);
}