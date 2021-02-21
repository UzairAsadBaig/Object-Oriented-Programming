#include<iostream>

using namespace std;


class DEPT{
    public:
    //--------------------------Getters and Setters-------------------------
     int getDeptno(){
        return this->deptno;
    }    
    void setDeptno(int a){
        this->deptno=a;
    }

    string getDname(){
        return this->dname;
    }    
    void setDname(string a){
        this->dname=a;
    }
    string getLoc(){
        return this->loc;
    }    
    void setLoc(string a){
        this->loc=a;
    }
    //------------------------Constructor-------------------------
    DEPT(){
        this->deptno=0;
    }
    DEPT(int a,string b,string c){
         setDeptno(a);
         setDname(b);
         setLoc(c);
    }

     ~DEPT(){
        // cout<<"\nDept deleted\n";
    }
    //---------------------------Input/Output Function-------------------
    void input(int a,string b,string c){
         setDeptno(a);
         setDname(b);
         setLoc(c);
    }

    friend istream &operator>>(istream &bin,DEPT &dept){
     cout<<"Enter the employe department number\n";
     bin>>dept.deptno;
     cout<<"Enter the department name\n";
     bin>>dept.dname;
     cout<<"Enter the employe loc\n";
     bin>>dept.loc;
      return bin;
    }

     friend ostream &operator<<(ostream &bout,DEPT &dept){
     cout<<"\nEmploye department number :";
     bout<<dept.deptno;
     cout<<"\nEmploye Department name :";
     bout<<dept.dname;
     cout<<"\nEmploye Department loc  :";
     bout<<dept.loc;;
     return bout;
     }
    private:
    int deptno;
    string dname;
    string loc;
    

};

class EMP{
    public:
    //--------------------------Getters and Setters-------------------------
    int getEmpno(){
        return this->empno;
    }    
    void setEmpno(int a){
        this->empno=a;
    }
    string getEname(){
        return this->ename;
    }    
    void setEname(string a){
        this->ename=a;
    }
    string getJob(){
        return this->job;
    }    
    void setJob(string a){
        this->job=a;
    }
    int getMgr(){
        return this->mgr;
    }    
    void setMgr(int a){
        this->mgr=a;
    }
     string getHireDate(){
        return this->hiredate;
    }    
    void setHireDate(string a){
        this->hiredate=a;
    }
    int getSal(){
        return this->sal;
    }    
    void setSal(int a){
        this->sal=a;
    }
    int getComm(){
        return this->comm;
    }    
    void setComm(int a){
        this->comm=a;
    }
    DEPT getDept(){
        return this->dept;
    }    
    void setDept(DEPT a){
        this->dept.input(a.getDeptno(),a.getDname(),a.getLoc());
    }

    //------------------------Constructor-------------------------
    EMP(){
        this->empno=0;
        this->mgr=0;
        this->sal=0;
        this->comm=0;
        this->dept.setDeptno(0);
    }
    EMP(int a,string b,string c,int d,string e, int f,int g,DEPT h){
         setEmpno(a);
         setEname(b);
         setJob(c);
         setMgr(d);
         setHireDate(e);
         setSal(f);
         setComm(g);
         setDept(h);
    }
     ~EMP(){
        // cout<<"\nEmp deleted\n";
    }
    //---------------------------Input/Output Function-------------------
    void input(int a,string b,string c,int d,string e, int f,int g,DEPT h){
         setEmpno(a);
         setEname(b);
         setJob(c);
         setMgr(d);
         setHireDate(e);
         setSal(f);
         setComm(g);
         setDept(h);
    }
    friend istream &operator>>(istream &bin,EMP &emp){
     cout<<"Enter the employe number\n";
     bin>>emp.empno;
     cout<<"Enter the employe name\n";
     bin>>emp.ename;
     cout<<"Enter the employe job\n";
     bin>>emp.job;
     cout<<"Enter the employe manager number\n";
     bin>>emp.mgr;
     cout<<"Enter the employe hiredate\n";
     bin>>emp.hiredate;
     cout<<"Enter the employe salary\n";
     bin>>emp.sal;
     cout<<"Enter the employe commision\n";
     bin>>emp.comm;
     bin>>emp.dept;
      return bin;
    }

     friend ostream &operator<<(ostream &bout,EMP &emp){
       cout<<"\nEmploye number :";
     bout<<emp.empno;
     cout<<"\nEmploye name :";
     bout<<emp.ename;
     cout<<"\nEmploye job  :";
     bout<<emp.job;
     cout<<"\nEmploye manager number :";
     bout<<emp.mgr;
     cout<<"\nEmploye hiredate :";
     bout<<emp.hiredate;
     cout<<"\nEmploye salary :";
     bout<<emp.sal;
     cout<<"\nEmploye commision :";
     bout<<emp.comm;
     bout<<emp.dept;
     return bout;
     }
    private:
    int empno;
    string ename;
    string job;
    int mgr;
    string hiredate;
    int sal;
    int comm;
    DEPT dept; //Composition

};


void dispEMPList(EMP emps[], int count);
void dispDEPTList(DEPT depts[], int count); 

int main(){
     DEPT depts[4];
     EMP *emps=new EMP[14];

     //to make it easy for you,I will give some random input myself
     for (int i = 0; i < 4; i++)
     {
         depts[i].input(i,"xyz", "Pakistan");
     }
    
    // Alternative
    // cout<<"Input four department information\n";
    // for (int i = 0; i < 4; i++)
    //  {
    //      cin>>depts[i];
    //  }

    //to make it easy for you,I will give some random input myself
     for (int i = 0; i < 14; i++)
     {
         emps[i].input(i*3,"uzair","CEO",0,"29 Nov,2002",1000*i,1000*i,depts[i%4]);
     }
    
    // Alternative
    // cout<<"Input four employe information\n";
    // for (int i = 0; i < 4; i++)
    //  {
    //      cin>>emps[i];
    //  }

    dispDEPTList(depts,4);
    dispEMPList(emps,14);
      delete[] emps;

      cout<<"\n The main() will end deleting all the depts\n";

}

void dispEMPList(EMP emps[], int count){
   for (int i = 0; i < count; i++)
   {
       cout<<emps[i]<<endl<<endl;
   }
   
} 
void dispDEPTList(DEPT depts[], int count){
    for (int i = 0; i < count; i++)
   {
       cout<<depts[i]<<endl<<endl;
   }
}