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

class employee
{

public:
    int empno;
    string cnic;
    string name;
    conDetails eCon; //Composition
    string type;


    employee(int a, string b, string c, conDetails &d,string typ)
    {
        this->empno = a;
        this->cnic = b;
        this->name = c;
        this->eCon = d;
        this->type=typ;
    }

    void disp(){
        cout<<"Name: "<<this->name<<"  CNIC: "<<this->cnic<<"  Empno: "<<this->empno<<"  Address: "<<this->eCon.address<<"  Phone: "<<this->eCon.phNum<<"  Type: "<<type<<"  ";
    }

    virtual long double calculatePay() = 0; //pure virtual function


};

class SalriedEmp : public employee
{

public:

    long double weeklySal;

    SalriedEmp(int a, string b, string c, conDetails &d,string typ, long double e) : employee(a, b, c, d,typ)
    {
        this->weeklySal = e;
    }

    long double calculatePay()
    {
        return this->weeklySal;
    }

    
};

class HourlyEmp : public employee
{

public:
    int hoursWorked;
    long double ratePerHour;
    const double overTimePay=200;

    HourlyEmp(int a, string b, string c, conDetails &d,string typ, int e, long double f) : employee(a, b, c, d,typ)
    {
        this->hoursWorked = e;
        this->ratePerHour = f;
    }

    long double calculatePay()
    {
        if(hoursWorked<=40)
        return this->hoursWorked * this->ratePerHour;
        else
        return (40 * this->ratePerHour)+((this->hoursWorked-40)*overTimePay);
    }
    
};

class CommissionEmp : public employee
{

public:
    long double salesTotal;
    float comPercent;

    CommissionEmp(int a, string b, string c, conDetails &d,string typ, long double e, float f) : employee(a, b, c, d,typ)
    {
        this->salesTotal = e;
        this->comPercent = f;
    }

    long double calculatePay()
    {
        return (this->salesTotal * this->comPercent) / 100;
    }

   
};

class Payroll
{
public:
    int count;
    //Lets say the total number of employes in that company is 1000
    employee *array[1000];

    Payroll(){
        count=0;
    }

    void addEmp(employee *a){
         array[count]=a;
         count++;
    }

    void dispPayroll(){
        for (int i = 0; i < count; i++)
        {
             array[i]->disp();
            cout<<"Pay: "<<array[i]->calculatePay()<<endl<<endl;
            

        }
        
    }



    
};



int main()
{
    //A dummy contact detail for all employes
    conDetails cd;
    cd.setDetails("Shalimar link road","03045937445");

    SalriedEmp *s= new SalriedEmp(45,"35201-xxxx-xxxx","Jhon",cd,"Salried",1500);        

    HourlyEmp *h= new HourlyEmp(121,"45201-xxxx-xxxx","Henry",cd,"Hourly",60,50);        

    CommissionEmp *c= new CommissionEmp(33,"55201-xxxx-xxxx","Peter",cd,"Commission",1000000,35);    

    Payroll roll;
  
    roll.addEmp(s);    
    roll.addEmp(h);    
    roll.addEmp(c);
  
    roll.dispPayroll();    

}