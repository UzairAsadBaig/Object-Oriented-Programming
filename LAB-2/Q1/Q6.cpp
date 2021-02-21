#include<iostream>

using namespace std;

struct Array{
        float A[5000];
};

void disp(const int &N,const Array &V){
     for (int i = 0; i < N; i++)
     {
         cout<<V.A[i]<<endl;
     }
     
}


int main()
{
   Array V;
    int N;
    cout<<"\nEnter a number between 10-10000\n";
    cin>>N;
    int i=1;
    while(i==1){
        if (N>10000 || N<10)
        {
           cout<<"\nWrong input! Try entering a number between 10-10000\n";
           cin>>N;
        }
        else{
            i=0;
        }
    }
        for (int i = 0; i < N; i++)
    {
        V.A[i]=rand();
        
    }
     disp(N,V);  

}
