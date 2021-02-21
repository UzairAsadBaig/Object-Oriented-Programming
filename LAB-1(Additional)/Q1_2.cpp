#include <iostream>
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

int main()
{
    vector a;
    a.x = 3.0623;
    a.y = 5.879;
    display(a);
}