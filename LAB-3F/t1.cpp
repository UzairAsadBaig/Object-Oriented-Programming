#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void display(string **line, int x)
{
    for (int i = 0; i < x; i++)
    {
        cout << "SONG : " << line[i][0];
        cout << "    SINGER : " << line[i][1] << endl;
    }
}

int main()
{
    ifstream str;
    str.open("music.txt");
    string s;
    int x = 0;
    while (!str.eof())
    {
        getline(str, s, ';');
        x++;
    }
    x--;
    str.close();
    ifstream fr;
    fr.open("music.txt");
    string **line = new string *[x];
    for (int i = 0; i < x; i++)
    {
        line[i] = new string[2];
        getline(fr, line[i][0], ',');
        getline(fr, line[i][1], ';');
    }
    fr.close();
    display(line, x);
    delete[] line;
}