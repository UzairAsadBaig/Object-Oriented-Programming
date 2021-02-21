#include<iostream>

using namespace std;

class List{
  private:
  int SPARE_VAL=100;
  int sizeOfArray;
  int sizeOfList;
  double **arr;

  void deallocArray()
    {
        delete[] arr;
        arr = NULL;
        sizeOfArray = sizeOfList = 0;
    }

  public:

//------------------------Getters / Setters--------------------------
void setSizeOfArray(int a){
   sizeOfArray=a;
}
int getSizeOfArray(){
   return sizeOfArray;
}


void setSizeOfList(int a){
   sizeOfList=a;
}
int getSizeOfList(){
   return sizeOfList;
}


void setElement(int a,double r,double i){
   arr[a][0]=r;
   arr[a][1]=i;
}
void printComplex(int i){
   cout<<arr[i][0]<<" + "<<arr[i][1]<<"i";
}
void printConj(int i){
   cout<<arr[i][0]<<" - "<<arr[i][1]<<"i";
}


void remove(int a){
   for (int i = a; i < getSizeOfList(); i++)
   {
    arr[i][0]=arr[i+1][0];
    arr[i][1]=arr[i+1][1];
   }
   sizeOfList--;
}
void append(double a,double b){
  setElement(getSizeOfList(),a,b);
  sizeOfList++;
}
void empty(){
    setSizeOfList(0);
}
void initializeList(){
    deallocArray();
     sizeOfArray=SPARE_VAL;
   sizeOfList=0;
   arr=new double*[sizeOfArray];
   for (int i = 0; i < sizeOfArray; i++)
   {
       arr[i]=new double[2];
   }

}
//------------------------Constructor / Destructor-------------------
  List(){
   sizeOfArray=SPARE_VAL;
   sizeOfList=0;
   arr=new double*[sizeOfArray];
   for (int i = 0; i < sizeOfArray; i++)
   {
       arr[i]=new double[2];
   }
  }

  ~List(){
      deallocArray();
  }

//------------------------- Display List  ----------------------------  
void showList(){
    for (int i = 0; i < getSizeOfList(); i++)
    {
        printComplex(i);
        cout<<endl;
    }
    
}
//------------------------Other Functions ---------------------------
void showConj(){
    for (int i = 0; i < getSizeOfList(); i++)
    {
        printConj(i);
        cout<<endl;
    }
}


friend void disposeList(List &l);
};
void initializeList(List &l);
void makeListEmpty(List &l);
void append(List  &l,double a,double b);
void showList(List &l);


int main(){
    List comp;
    initializeList(comp);
    append(comp, 3.45, 3.45);
    append(comp, 2.72, 2.72);
    append(comp, 3.91, 3.91);
    append(comp, 2.00, 2.00);
    append(comp, 2.75, 2.75);
    append(comp, 2.25, 2.25);
    append(comp, 3.31, 3.31);
    append(comp, 3.83, 3.83);
    append(comp, 2.43, 2.43);
    append(comp, 1.83, 1.83);
    // makeListEmpty(comp);
    append(comp, 2.94, 2.94);
    append(comp, 3.65, 3.65);
    append(comp, 2.98, 2.98);

    showList(comp);

    disposeList(comp);
    return 0;

}

void initializeList(List &l){
    l.initializeList();
}
void append(List &l,double a,double b){
    l.append(a,b);
}
void showList(List &l){
    l.showList();
}
void makeListEmpty(List &l){
    l.empty();
}
void disposeList(List &l){
 l.deallocArray();   
}
