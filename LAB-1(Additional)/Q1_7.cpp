#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct vector
{
    double x;
    double y;
};

void equal(vector &a1, vector &a2)
{
    if (a1.x == a2.x)
    {
        if (a1.y == a2.y)
        {
            cout << "\nBoth vectors are equal.";
        }
        else
        {
            cout << "\nBoth vectors are not equal.";
        }
    }
    else
    {
        cout << "\nBoth vectors are not equal.";
    }
}

vector Input(string input)
{
    vector a;
    stringstream ss;
    ss << input;
    ss >> a.x;
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
    equal(a1, a2);
}