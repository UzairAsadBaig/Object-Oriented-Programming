#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct vector
{
    double x;
    double y;
};

void display(double &a)
{
    cout << "The dot product of given vector is " << a << endl;
}

void product(vector &a1, vector &a2)
{
    double pa;
    pa = (a1.x) * (a2.x) + (a1.y) * (a2.y);
    display(pa);
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
    product(a1, a2);
}