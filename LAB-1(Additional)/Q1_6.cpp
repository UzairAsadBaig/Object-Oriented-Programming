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

void xAngle(vector &a)
{
    double x2, y2, mag, cos, angle;
    x2 = (a.x) * (a.x);
    y2 = (a.y) * (a.y);
    mag = sqrt(x2 + y2);
    cos = (a.x) / mag;
    angle = (acos(cos)) * (180 * 7 / 22);
    cout << "The angle of given vector along x-axis is " << angle << endl;
}

void Input(string &input)
{
    vector a;
    stringstream ss;
    ss << input;
    ss >> a.x;
    ss.ignore(1);
    ss >> a.y;
    xAngle(a);
}

int main()
{
    string input;
    cout << "Input a vector in the form of xi+yj and press enter.\n";
    cin >> input;
    Input(input);
}