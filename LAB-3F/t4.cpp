#include <iostream>
#include <cmath>
#include <iomanip>
#include <new>
#include <fstream>
#include <string>



using namespace std;





int main()
{ 
   cout<<"Enter the file name \n";  //The file name will be provided by the user
   string f;
   cin>>f;
   ofstream fw;
   fw.open(f);    //Opening the file
   srand(0);
   double fl=5.0;
    
 
    long int head=rand();
    fw<<head<<"\n";
    long int i=0;
    while(i < head)
    {
    
        long int nn=rand();
        fw<<nn<<" ";
        long int j=0;
        double u;
        while(j < nn)
        {
            u=double(rand())/double((RAND_MAX)) * fl;  //Generating Random Numbers
            fw<<u<<" "; //Storing on file
            j++;
        }
        fw<<"\n";
        i++;
    }

}
