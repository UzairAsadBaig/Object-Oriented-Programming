#include<iostream>
#include<sstream>
#include<string>
using namespace std;

struct complex{
    double real;
    double imag;
};


void display(complex &a){
    cout<<"The negative of the Complex number is ("<<a.real<<","<<a.imag<<")";
}

void Negative(complex &a){
    complex na;
    na.real=(a.real)*-1;
    na.imag=(a.imag)*-1;
    display(na);
}

void Input(string input){
    complex a;
    stringstream ss;
    ss<<input;
    ss>>a.real;
    ss>>a.imag;
    Negative(a);
}

int main(){
    string input;
    cout<<"Input a complex number in the form of a+bi and press enter.\n";
    cin>>input;
    Input(input);

}