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

void display(complex &a)
{
    cout << "\nYour result is (" << a.real << "," << a.imag << ")";
}

void Negative(complex &a)
{
    complex na;
    na.real = (a.real) * -1;
    na.imag = (a.imag) * -1;
    display(na);
}

void Conjugate(complex &a)
{
    complex ca;
    ca.real = a.real;
    ca.imag = (a.imag) * -1;
    display(ca);
}

void Magnitude(complex &a)
{
    double r, i, mag;
    r = a.real * a.real;
    i = a.imag * a.imag;
    mag = sqrt(r + i);
    cout << "\nMagnitude is " << mag;
}

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

void sum(complex &a1, complex &a2)
{
    complex sa;
    sa.real = a1.real + a2.real;
    sa.imag = a1.imag + a2.imag;
    display(sa);
}

void product(complex &a1, complex &a2)
{
    complex pa;
    pa.real = (a1.real) * (a2.real) - ((a1.imag) * (a2.imag));
    pa.imag = (a1.imag) * (a2.real) + (a2.imag) * (a1.real);
    display(pa);
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
    char select;
    cout << "Select the function by entering the respective number.\n\n1) Negative of a Complex number\n2) Conjugate of a Complex number\n3) Magnitude of a Complex number\n4) Sum of a Complex numbers\n5) Product of a Complex numbers\n6) Multiplicative inverse of Complex number\n7) Equality test of Complex numbers\n";
    cin >> select;
    if (select == '1')
    {
        string input;
        complex a;
        cout << "Input a complex number in the form of a+bi and press enter.\n";
        cin >> input;
        a = Input(input);
        Negative(a);
    }

    if (select == '2')
    {
        string input;
        complex a;
        cout << "Input a complex number in the form of a+bi and press enter.\n";
        cin >> input;
        a = Input(input);
        Conjugate(a);
    }

    if (select == '3')
    {
        string input;
        complex a;
        cout << "Input a complex number in the form of a+bi and press enter.\n";
        cin >> input;
        a = Input(input);
        Magnitude(a);
    }

    if (select == '4')
    {
        string input1, input2;
        complex a1, a2;
        cout << "Input first complex number in the form of a+bi and press enter.\n";
        cin >> input1;
        a1 = Input(input1);
        cout << "Input Second complex number in the form of a+bi and press enter.\n";
        cin >> input2;
        a2 = Input(input2);
        sum(a1, a2);
    }

    if (select == '5')
    {
        string input1, input2;
        complex a1, a2;
        cout << "Input first complex number in the form of a+bi and press enter.\n";
        cin >> input1;
        a1 = Input(input1);
        cout << "Input Second complex number in the form of a+bi and press enter.\n";
        cin >> input2;
        a2 = Input(input2);
        product(a1, a2);
    }

    if (select == '6')
    {
        string input;
        complex a;
        cout << "Input complex number in the form of a+bi and press enter.\n";
        cin >> input;
        a = Input(input);
        multInverse(a);
    }

    if (select == '7')
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
}
