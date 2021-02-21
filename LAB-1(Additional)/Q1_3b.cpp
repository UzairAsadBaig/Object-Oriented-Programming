#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct vector
{
    double x;
    double y;
};

void display(vector a)
{
    cout << "Your result is (" << a.x << "," << a.y << ")";
}

void Input(string &input)
{
    vector a;
    stringstream ss;
    ss << input;
    ss >> a.x;
    ss.ignore(1);
    ss >> a.y;
    display(a);
}

int main()
{
    string input;
    cout << "Input a vector in the form of xi+yj and press enter.\n";
    cin >> input;
    Input(input);
}