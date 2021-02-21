#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct vector
{
    double x;
    double y;
};

void display(vector &a)
{
    cout << "Your result is (" << a.x << "," << a.y << ")";
}

void product(vector &v, double s)
{
    vector sv;
    sv.x = (v.x) * s;
    sv.y = (v.y) * s;
    display(sv);
}

vector Input(string input)
{
    vector a;
    stringstream ss;
    ss << input;
    ss >> a.x;
    ss.ignore(1);
    ss >> a.y;
    return a;
}

int main()
{
    string input;
    vector v;
    double s;
    cout << "Input a vector in the form of xi+yj and press enter.\n";
    cin >> input;
    v = Input(input);
    cout << "Input a Scalar number and press enter.\n";
    cin >> s;
    product(v, s);
}