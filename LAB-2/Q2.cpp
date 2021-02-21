#include<iostream>

using namespace std;

struct List{
      float A[5000];
      int N;
};

void disp(const List &D){
     for (int i = 0; i < D.N; i++)
     {
         cout<<D.A[i]<<endl;
     }
     
}

int main()
{
 
    List D,DC;
    cout<<"\nEnter a number between 10-10000\n";
    cin>>D.N;
    int i=1;
    while(i==1){
        if (D.N>10000 || D.N<10)
        {
           cout<<"\nWrong input! Try entering a number between 10-10000\n";
           cin>>D.N;
        }
        else{
            i=0;
        }
    }
     for (int i = 0; i < D.N; i++)
    {
        D.A[i]=rand();
        
    }
    
   DC=D;

   disp(DC);   
    
 

}
