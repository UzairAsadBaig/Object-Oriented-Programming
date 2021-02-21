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

void display(complex a)
{
    cout << "\nYour result is (" << a.real << "," << a.imag << ")";
}

complex Negative(complex a)
{
    complex na;
    na.real = (a.real) * -1;
    na.imag = (a.imag) * -1;
    return na;
}

complex Conjugate(complex a)
{
    complex ca;
    ca.real = a.real;
    ca.imag = (a.imag) * -1;
    return ca;
}

complex sum(complex a1, complex a2)
{
    complex sa;
    sa.real = a1.real + a2.real;
    sa.imag = a1.imag + a2.imag;
    return sa;
}

complex product(complex a1, complex a2)
{
    complex pa;
    pa.real = (a1.real) * (a2.real) - ((a1.imag) * (a2.imag));
    pa.imag = (a1.imag) * (a2.real) + (a2.imag) * (a1.real);
    return pa;
}

complex multInverse(complex a)
{
    complex mia;
    mia.real = a.real / (((a.real) * (a.real)) + ((a.imag) * (a.imag)));
    mia.imag = a.imag / (((a.real) * (a.real)) + ((a.imag) * (a.imag)));
    return mia;
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
    complex w, x, y, z;
    w.real = 2;
    w.imag = 0;
    x.real = -4;
    x.imag = -2;
    y.real = 5;
    y.imag = -1;
    z.real = 0;
    z.imag = -1;

    complex a = sum(product(sum(w, z), Conjugate(x)), Negative(y));
    display(a);
}
