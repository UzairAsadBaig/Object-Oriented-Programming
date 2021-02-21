#include <iostream>
#include <sstream>
#include <iomanip>
#include <sstream>

using namespace std;

class Time
{

public:
    //----------------------------Getters and Setters--------------------------
    void setSec(int i)
    {
        if (i < 60 || i >= 0)
        {
            this->sec = i;
        }
        else
        {
            cout << "\nSeconds must be between (0-59),Try Again!\n";
            cin >> i;
            setSec(i);
        }
    }
    int getSec()
    {
        return this->sec;
    }
    void setMin(int i)
    {
        if (i < 60 || i >= 0)
        {
            this->min = i;
        }
        else
        {
            cout << "\nMinutes must be between (0-59),Try Again!\n";
            cin >> i;
            setMin(i);
        }
    }
    int getMin()
    {
        return this->min;
    }
    void setHour(int i)
    {
        if (i < 24 || i >= 0)
        {
            this->hour = i;
        }
        else
        {
            cout << "\nHours must be between (0-23),Try Again!\n";
            cin >> i;
            setHour(i);
        }
    }
    int getHour()
    {
        return this->hour;
    }

    //-------------------------------Constructors/Destructor-----------------------------
    Time()
    {
    }
    Time(int h, int m, int s)
    {
        this->setHour(h);
        this->setMin(m);
        this->setSec(s);
    }
    Time(Time &a)
    {
        this->setHour(a.getHour());
        this->setMin(a.getMin());
        this->setSec(a.getSec());
    }

    ~Time(){

    }

    //--------------------------------Displaying Time-----------------------------
    void dispT()
    {
        cout << setfill('0') << setw(2) << this->hour << ":";
        cout << setfill('0') << setw(2) << this->min << ":";
        cout << setfill('0') << setw(2) << this->sec << endl;
    }

    //--------------------------------Operator Overloading-------------------------
    double operator-(Time tame)
    {
        double a, b, diff;
        a = (this->hour * 3600) + (this->min * 60) + (this->sec);
        b = (tame.hour * 3600) + (tame.min * 60) + (tame.sec);
        diff = a - b;
        return diff;
    }

    void operator+(int a)
    {

        int test = this->sec + a;
        if (test >= 60)
        {
            test = test - 60;
            this->sec = test;
            this->min++;
        }
        else{
            this->sec=test;
        }
    }
    void operator*(int a)
    {
        int test = this->min + a;
        if (test >= 60)
        {
            test = test - 60;
            this->min = test;
            this->hour++;
        }
        else{
            this->min=test;
        }
    }
    void operator/(int a)
    {
        int test = this->hour + a;
        if (test >= 24)
        {
            test = test - 24;
            this->hour = test;
        }
        else{
            this->hour=test;
        }
    }
    //Binary Comparison
    bool operator>(Time tame)
    {
        double first = (this->hour * 3600) + (this->min * 60) + (this->sec);
        double second = (tame.hour * 3600) + (tame.min * 60) + (tame.sec);
        if (first > second)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool operator<(Time tame)
    {
        double first = (this->hour * 3600) + (this->min * 60) + (this->sec);
        double second = (tame.hour * 3600) + (tame.min * 60) + (tame.sec);
        if (first < second)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool operator>=(Time tame)
    {
        double first = (this->hour * 3600) + (this->min * 60) + (this->sec);
        double second = (tame.hour * 3600) + (tame.min * 60) + (tame.sec);
        if (first >= second)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool operator<=(Time tame)
    {
        double first = (this->hour * 3600) + (this->min * 60) + (this->sec);
        double second = (tame.hour * 3600) + (tame.min * 60) + (tame.sec);
        if (first <= second)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool operator==(Time tame)
    {
        double first = (this->hour * 3600) + (this->min * 60) + (this->sec);
        double second = (tame.hour * 3600) + (tame.min * 60) + (tame.sec);
        if (first == second)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool operator!=(Time tame)
    {
        double first = (this->hour * 3600) + (this->min * 60) + (this->sec);
        double second = (tame.hour * 3600) + (tame.min * 60) + (tame.sec);
        if (first != second)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void operator=(Time &a){
       sec=a.getSec();
       min=a.getMin();
       hour=a.getHour();
    }
    //-------------------------Insertion/Extraction Operator---------------------------
    friend istream &operator>>(istream &bin, Time &t)
    {
        cout << "Enter time in format(hh:mm:ss)\n";
             
        string a;
        stringstream ss;
        int h, m, s;
        bin >> a;
        ss << a;
        ss >> h;
        ss.ignore(1);
        ss >> m;
        ss.ignore(1);
        ss >> s;
        t.setHour(h);
        t.setMin(m);
        t.setSec(s);

        return bin;
    }
    friend ostream &operator<<(ostream &bout, Time &t)
    {
        bout << setfill('0') << setw(2) << t.hour << ":";
        bout << setfill('0') << setw(2) << t.min << ":";
        bout << setfill('0') << setw(2) << t.sec ;

        return bout;
    }

    //--------------------------Cast Function---------------------
    operator double() const
    {   double a=this->hour+this->min/60+this->sec/3600;
        return a;
    }

private:
    int sec;
    int min;
    int hour;
};

int main()
{
    Time a,b;
    cin>>a;
    cin>>b;
    cout<<"\nDifference between "<<a<<" and "<<b<<" in seconds is "<<a-b;
    cout<<endl<<a<<" +  30secs   = ";
    a+30;
    cout<<a;
    cout<<endl<<a<<" +  30mins   = ";
    a*30;
    cout<<a;
    cout<<endl<<a<<" +  30hours  = ";
    a/30;
    cout<<a;
    cout<<endl<<a<<" <  "<<b<<" = ";
    if(a<b){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    cout<<endl<<a<<" >  "<<b<<" = ";
    if(a>b){ 
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    cout<<endl<<a<<" <= "<<b<<" = ";
    if(a<=b){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    cout<<endl<<a<<" >= "<<b<<" = ";
    if(a>=b){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    cout<<endl<<a<<" == "<<b<<" = ";
    if(a==b){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    cout<<endl<<a<<" != "<<b<<" = ";
    if(a!=b){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    cout<<"\nCasting the Time "<<a<<"  to double "<<double(a);
}