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

void sum(vector &a1, vector &a2)
{
    vector sa;
    sa.x = a1.x + a2.x;
    sa.y = a1.y + a2.y;
    display(sa);
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
    string input1, input2;
    vector a1, a2;
    cout << "Input first vector in the form of xi+yj and press enter.\n";
    cin >> input1;
    a1 = Input(input1);
    cout << "Input first vector in the form of xi+yj and press enter.\n";
    cin >> input2;
    a2 = Input(input2);
    sum(a1, a2);
}