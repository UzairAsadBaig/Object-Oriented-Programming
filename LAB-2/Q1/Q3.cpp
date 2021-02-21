#include<iostream>

using namespace std;

void disp(const int &N,const float A[]){ //Array is already passed as refrence
     for (int i = 0; i < N; i++)
     {
         cout<<A[i]<<endl;
     }
     
}

int main()
{
    float A[5000];
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
        A[i]=rand();
        
    }
    disp(N,A);    
    
    

}
