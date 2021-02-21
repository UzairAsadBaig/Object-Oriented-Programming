#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class conDetails
{
    public:
    string address;
    string phNum;
    
    void setDetails(string a,string b){
      this->address=a;
      this->phNum=b;
    }

};

class Student
{

public:
    int stdno;
    string cnic;
    string name;
    conDetails eCon; //Composition
    string course;

    Student(int a, string b, string c, conDetails &d, string e)
    {
        this->stdno = a;
        this->cnic = b;
        this->name = c;
        this->eCon = d;
        this->course=e;
    }

    void disp(){
        cout<<"Name: "<<this->name<<"  CNIC: "<<this->cnic<<"  Stdno: "<<this->stdno<<"  Address: "<<this->eCon.address<<"  Phone: "<<this->eCon.phNum<<"  Course: "<<course<<"  ";
    }

    virtual double calculateOPM() = 0; //pure virtual function


};

class Math : public Student
{

public:

    double percentMarks;

    Math(int a, string b, string c, conDetails &d,string cor, double e) : Student(a, b, c, d,cor)
    {
        this->percentMarks = e;
    }

    double calculateOPM()
    {
        return this->percentMarks;
    }

    
};

class Computer : public Student
{

public:
    double examMout20;
    double examMout50;
    int classPart;
    

    Computer(int a, string b, string c, conDetails &d,string cor, double e, double f,int g) : Student(a, b, c, d,cor)
    {
        this->examMout20 = e;
        this->examMout50 = f;
        this->classPart = g;
    }

    double calculateOPM()
    {
        if((((this->examMout20/20)*40) + ((this->examMout50/50)*60) + this->classPart)<=100)
        return ((this->examMout20/20)*40) + ((this->examMout50/50)*60) + this->classPart;
        else 
        return 100;
        
    }
    
};

class English : public Student
{

public:
    double teacherMout100;
    float avgRateStd;

    English(int a, string b, string c, conDetails &d,string cor, double e, float f) : Student(a, b, c, d,cor)
    {
        this->teacherMout100 = e;
        if(f<=1.0 && f>=0.6)
        this->avgRateStd = f;
        else{
            float a;
            cout<<"\nWrong Input for average student rate,Enter a value between 0.6 and 1.0\n";
            cin>>a;
            this->avgRateStd=a;
        }
    }

    double calculateOPM()
    {
        return this->teacherMout100 * this->avgRateStd;
    }

   
};

class Gazette
{
public:
    int count;
    //Lets say the total number of employes in that company is 1000
    Student *array[1000];

    Gazette(){
        count=0;
    }

    void addEmp(Student *a){
         array[count]=a;
         count++;
    }

    void dispGazette(){
        for (int i = 0; i < count; i++)
        {
             array[i]->disp();
            cout<<"Marks: "<<array[i]->calculateOPM()<<endl<<endl;
            

        }
        
    }



    
};



int main()
{
    //A dummy contact detail for all employes
    conDetails cd;
    cd.setDetails("Shalimar link road","03045937445");

    Math *m= new Math(45,"35201-xxxx-xxxx","Jhon",cd,"Math",98);        

    Computer *c= new Computer(121,"45201-xxxx-xxxx","Henry",cd,"Computer",18,45,7);        

    English *e= new English(33,"55201-xxxx-xxxx","Peter",cd,"English",95,0.9);    

    Gazette roll;
  
    roll.addEmp(m);    
    roll.addEmp(c);    
    roll.addEmp(e);
  
    roll.dispGazette();    

}