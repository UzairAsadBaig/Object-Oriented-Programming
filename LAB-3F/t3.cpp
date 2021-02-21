#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void display(string *line, int x)
{
  for (int i = 0; i < x; i++)
  {
    cout << "Roll Number: ";
    for (int z = 0; z < 10; z++)
    {
      cout << line[i][z];
    }

    cout << "  Name: ";
    for (int z = 10; z < 41; z++)
    {
      cout << line[i][z];
    }

    cout << "  CRS: ";
    for (int z = 41; z < 44; z++)
    {
      cout << line[i][z];
    }

    cout << "  MM: ";
    for (int z = 47; z < 49; z++)
    {
      cout << line[i][z];
    }

    cout << "  SM: ";
    for (int z = 49; z < 51; z++)
    {
      cout << line[i][z];
    }

    cout << "  FM: ";
    for (int z = 51; z < 53; z++)
    {
      cout << line[i][z];
    }

    cout << "  DGR: ";
    for (int z = 53; z < 55; z++)
    {
      cout << line[i][z];
    }
    cout << endl
         << endl;
  }
}

int main()
{
  ifstream str;
  str.open("grades2.txt");
  string c;
  int x = -2;

  while (!str.eof())
  {
    getline(str, c);
    if (c[0] != '\0')
    {
      x++;
    }
  }
  str.close();

  ifstream fr;
  fr.open("grades2.txt");
  getline(fr, c);
  getline(fr, c);
  string *line = new string[x];
  for (int i = 0; i < x; i++)
  {
    getline(fr, line[i]);
  }
  fr.close();

  display(line, x);

  delete[] line;
}