#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

struct vector
{
    double x;
    double y;
};

void Magnitude(vector &a)
{
    double x2, y2, mag;
    x2 = (a.x) * (a.x);
    y2 = (a.y) * (a.y);
    mag = sqrt(x2 + y2);
    cout << "The magnitude of given vector is " << mag << endl;
}

void Input(string &input)
{
    vector a;
    stringstream ss;
    ss << input;
    ss >> a.x;
    ss.ignore(1);
    ss >> a.y;
    Magnitude(a);
}

int main()
{
    string input;
    cout << "Input a vector in the form of xi+yj and press enter.\n";
    cin >> input;
    Input(input);
}