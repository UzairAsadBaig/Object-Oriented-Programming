#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct complex
{
    double real;
    double imag;
};

void equal(complex &a1, complex &a2)
{
    if (a1.real == a2.real)
    {
        if (a1.imag == a2.imag)
        {
            cout << "\nBoth complex numers are equal.";
        }
        else
        {
            cout << "\nBoth complex numbers are not equal.";
        }
    }
    else
    {
        cout << "\nBoth complex numbers are not equal.";
    }
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
    string input1, input2;
    complex a1, a2;
    cout << "Input first complex number in the form of a+bi and press enter.\n";
    cin >> input1;
    a1 = Input(input1);
    cout << "Input Second complex number in the form of a+bi and press enter.\n";
    cin >> input2;
    a2 = Input(input2);
    equal(a1, a2);
}