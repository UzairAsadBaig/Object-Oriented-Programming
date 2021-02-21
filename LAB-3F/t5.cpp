#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;



int main()
{
	float num;  
	cout<<"Enter the file name \n";  //The file name will be provided by the user
    string f;
    cin>>f;
	ifstream fr;
	fr.open(f);
	ofstream fw;
    cout<<"Enter the file name \n";  //The file name will be provided by the user
	string A;
	cin>>A;
	fw.open(A);
	int count,fls;
	fr >> count;

	for (int i = 0; i < count; i++)
	{
		double *avg = new double;
		double *summation = new double;
		fr >> fls;
		for ( int j = 0; j < fls; j++)
		{
			fr >> num;
			*summation = *summation + num;
		}
		*avg =  *summation/fls;
		fw<<*avg ;
		
	}

}
