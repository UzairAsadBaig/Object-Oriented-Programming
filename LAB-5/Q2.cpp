#include <iostream>
#include <cstring>
using namespace std;

class Teacher
{
public:
  //----------------------GETTERS/SETTERS---------------------
  void setName(string n)
  {
    this->name = n;
  }
  string getName() const
  {
    return this->name;
  }
  void setAge(int a)
  {
    this->age = a;
  }
  int getAge() const
  {
    return this->age;
  }
  void setSchool(string s)
  {
    this->school = s;
  }
  string getSchool() const
  {
    return this->school;
  }

  //qualification, b for bs,m for ms and p for phd
  void setQual(char q)
  {
    while (1)
    {
      if (q == 'b' || q == 'B' || q == 'm' || q == 'M' || q == 'p' || q == 'P')
      {
        this->qual = q;
        break;
      }
      else
      {
        {
          cout << "\nWrong input,try 'b' for BSc,'m' for MSc and 'p' for PHd\n";
          cin >> q;
          setQual(q);
        }
      }
    }
  }
  char getQual() const
  {
    return this->qual;
  }

  //s for science , a for arts;
  void setSubject(char s)
  {
    while (1)
    {
      if (s == 's' || s == 'S' || s == 'a' || s == 'A')
      {
        this->subject = s;
        break;
      }
      else
      {
        {
          cout << "\nWrong input,try 's' for Science and 'a' for Arts\n";
          cin >> s;
          setSubject(s);
        }
      }
    }
  }
  char getSubject() const
  {
    return this->subject;
  }

  void setClasses(int cl)
  {
    this->classes = cl;
  }
  int getClasses() const
  {
    return this->classes;
  }

  //E for elementary, P for primary,S for secondary aand H for higher
  void setLevel(char l)
  {
    if (l == 'e' || l == 'E' || l == 'p' || l == 'P' || l == 's' || l == 'S' || l == 'h' || l == 'H')
    {
      this->level = l;
    }
    else
    {
      cout << "\nWrong input in level, try E for elementary, P for primary,S for secondary aand H for high school.\n";
      cin >> l;
      setLevel(l);
    }
  }
  char getLevel() const
  {
    return this->level;
  }
  void setPay(double p)
  {
    this->pay = p;
  }
  double getPay() const
  {
    return this->pay;
  }
  //G for government and P for private
  void setSector(char s)
  {
    if (s == 'g' || s == 'G' || s == 'p' || s == 'P')
    {
      this->sector = s;
      if (s == 'g' || s == 'G')
      {
        cout << "\nEnter the government scale (form 1 to 22).\n";

        while (1)
        {
          cin >> this->grade;
          if (this->grade > 22 || this->grade < 0)
          {
            cout << "\nWrong input,Enter the government scale (form 1 to 22)\n";
            continue;
          }
          else
          {
            break;
          }
        }
      }
      else
      {
        this->grade = 0;
      }
    }
  }
  char getSector() const
  {
    return this->sector;
  }
  //  void setGrade(int g){
  //    this->grade=g;
  //  }
  int getGrade() const
  {
    return this->grade;
  }

  //--------------------INPUT FUNCTION------------------------
  void inputT(string n, int a, string s, char q, char sub, int clas, char l, double p, char sec)
  {
    setName(n);
    setAge(a);
    setSchool(s);
    setQual(q);
    setSubject(sub);
    setClasses(clas);
    setLevel(l);
    setPay(p);
    setSector(sec);
  }

  //--------------------OUTPUT FUNCTION-------------------------
  void displayT()
  {
    cout << "\nName: " << this->getName();
    cout << "\nAge: " << this->getAge();
    cout << "\nSchool: " << this->getSchool();
    cout << "\nQualification: " << this->getQual();
    cout << "\nSubject: " << this->getSubject();
    cout << "\nClasses: " << this->getClasses();
    cout << "\nLevel: " << this->getLevel();
    cout << "\nPay: " << this->getPay();
    cout << "\nSector: " << this->getSector();
    if (this->getSector() == 'g' || this->getSector() == 'G')
    {
      cout << "\nGrade: " << this->getGrade();
    }
  }

  //--------------------OUTPUT OPERATOR------------------------
  friend ostream &operator<<(ostream &bout, const Teacher &t)
  {
    bout << "\nName: " << t.getName();
    bout << "\nAge: " << t.getAge();
    bout << "\nSchool: " << t.getSchool();
    bout << "\nQualification: " << t.getQual();
    bout << "\nSubject: " << t.getSubject();
    bout << "\nClasses: " << t.getClasses();
    bout << "\nLevel: " << t.getLevel();
    bout << "\nPay: " << t.getPay();
    bout << "\nSector: " << t.getSector();
    if (t.getSector() == 'g' || t.getSector() == 'G')
    {
      bout << "\nGrade: " << t.getGrade();
    }
    return bout;
  }
  //--------------------INTPUT OPERATOR------------------------
  friend istream &operator>>(istream &bin, Teacher &t)
  {
    cout << "\nName: ";
    bin >> t.name;
    cout << "\nAge: ";
    bin >> t.age;
    cout << "\nSchool: ";
    bin >> t.school;
    cout << "\nQualification: ";
    char q;
    cin >> q;
    t.setQual(q);
    cout << "\nSubject: ";
    char s;
    cin >> s;
    t.setSubject(s);
    cout << "\nClasses: ";
    int cl;
    cin >> cl;
    t.setClasses(cl);
    cout << "\nLevel: ";
    while (1)
    {
      bin >> t.level;
      if (t.level == 'e' || t.level == 'E' || t.level == 'p' || t.level == 'P' || t.level == 's' || t.level == 'S' || t.level == 'h' || t.level == 'H')
      {
        break;
      }
      else
      {
        cout << "\nWrong input in level, try E for elementary, P for primary,S for secondary aand H for high school.\n";
        continue;
      }
    }
    cout << "\nPay: ";
    bin >> t.pay;
    cout << "\nSector: ";

    while (1)
    {
      bin >> t.sector;
      if (t.sector == 'g' || t.sector == 'G' || t.sector == 'p' || t.sector == 'P')
      {
        if (t.sector == 'g' || t.sector == 'G')
        {
          cout << "\nGrade: ";
          while (1)
          {
            bin >> t.grade;
            if (t.grade > 22 || t.grade < 0)
            {
              cout << "\nWrong input,Enter the government scale (form 1 to 22)\n";
              continue;
            }
            else
            {
              break;
            }
          }
        }
        break;
      }
      else
      {
        cout << "\nWrong input! , try 'g' for government and 'p' for private\n";
        continue;
      }
    }
    return bin;
  }

  //----------------------CONSTRUCTORS----------------------
  Teacher()
  {
  }
  Teacher(string n, int a, string s, char q, char sub, int clas, char l, double p, char sec)
  {
    setName(n);
    setAge(a);
    setSchool(s);
    setQual(q);
    setSubject(sub);
    setClasses(clas);
    setLevel(l);
    setPay(p);
    setSector(sec);
  }

  //----------------------OTHER FUNCTIONS----------------------
  void changeSec()
  {
    if (this->sector == 'G' || this->sector == 'g')
    {
      this->sector = 'p';
    }
    else
    {

      this->sector = 'g';
    }
  }

  void incLevel()
  {
    if (this->level == 'e' || this->level == 'E')
    {
      this->level = 'p';
    }
    else if (this->level == 'p' || this->level == 'P')
    {
      this->level = 's';
    }

    else
    {
      this->level = 'h';
    }
  }
  void decLevel()
  {
    if (this->level == 'h' || this->level == 'H')
    {
      this->level = 's';
    }
    else if (this->level == 's' || this->level == 'S')
    {
      this->level = 'p';
    }

    else
    {
      this->level = 'e';
    }
  }

  void incPay(double p)
  {
    this->pay += p;
  }
  void decPay(double p)
  {
    this->pay -= p;
  }

  void incAge()
  {
    this->age += 1;
  }

  void incGrade()
  {
    if (this->sector == 'G' || this->sector == 'g')
    {
      this->grade += 1;
    }
    else
    {
      {
        cout << "\nTeacher works in private sector grade cannot be increased\n";
      }
    }
  }
  void incQual()
  {
    if (this->qual == 'b' || this->qual == 'B')
    {
      this->qual = 'm';
    }
    else
    {
      this->qual = 'p';
    }
  }
  void shiftSub()
  {
    if (this->subject == 's')
    {
      this->subject = 'a';
    }
    else
    {
      this->subject = 's';
    }
  }
  void incClasses(int a)
  {
    this->classes += a;
  }

  //-------------------DATA MEMBERS---------------------
private:
  string name;
  int age;
  string school;
  char qual;
  char subject;
  int classes;
  char level;
  double pay;
  char sector;
  int grade;
};

//---------------------MAIN FUNCTION-------------------
int main()
{
}
