#include <iostream>
#include <stdlib.h>

using namespace std;

class robot
{
public:
    string getRobotName() const
    {
        return this->name;
    }
    void setRobotName(string n)
    {
        this->name = n;
    }
    int getLocationX() const
    {
        return this->row;
    }
    void setLocationX(int v)
    {

        if (v <= 99 && v >= 0)
        {
            this->row = v;
        }
        else
        {
            cout << this->name << "'s x-axis value is exceeding the range of  90\n Try again.\n";
            int a;
            cin >> a;
            this->setLocationX(a);
        }
    }
    int getLocationY() const
    {
        return this->col;
    }
    void setLocationY(int v)
    {

        if (v <= 99 && v >= 0)
        {
            this->col = v;
        }
        else
        {
            cout << this->name << "'s y-axis value is exceeding the range of  90\n Try again.\n";
            int a;
            cin >> a;
            this->setLocationY(a);
        }
    }
    char getDirection() const
    {
        return this->direction;
    }
    void setDirection(char d)
    {
        if (d != 'u' && d != 'd' && d != 'r' && d != 'l')
        {
            cout << this->name << "'s direction is incorrect.\n Try again.\n";
            char a;
            cin >> a;
            this->setDirection(a);
        }
        else
        {
            this->direction = d;
        }
    }
    void setRobot(string n, int cx, int cy, char d)
    {
        this->setRobotName(n);
        this->setLocationX(cx);
        this->setLocationY(cy);
        this->setDirection(d);
    }
    bool canStep()
    {
        if (this->direction == 'l')
        {
            if (this->row - 1 >= 0 && this->row - 1 <= 99)
            {
                return true;
            }
        }
        else if (this->direction == 'r')
        {
            if (this->row + 1 >= 0 && this->row + 1 <= 99)
            {
                return true;
            }
        }
        else if (this->direction == 'u')
        {
            if (this->col + 1 >= 0 && this->col + 1 <= 99)
            {
                return true;
            }
        }
        else if (this->direction == 'd')
        {
            if (this->col - 1 >= 0 && this->col - 1 <= 99)
            {
                return true;
            }
        }
        return false;
    }
    void takeStep()
    {
        if (this->canStep())
        {
            if (this->direction == 'l')
            {
                this->row -= 1;
            }
            else if (this->direction == 'r')
            {
                this->row += 1;
            }
            else if (this->direction == 'u')
            {
                this->col += 1;
            }
            else if (this->direction == 'd')
            {
                this->col -= 1;
            }
        }
    }
    void turnLeft()
    {
        if (this->direction == 'l')
        {
            this->direction = 'd';
        }
        else if (this->direction == 'r')
        {
            this->direction = 'u';
        }
        else if (this->direction == 'd')
        {
            this->direction = 'r';
        }
        else if (this->direction == 'u')
        {
            this->direction = 'l';
        }
    }
    void turnRight()
    {
        if (this->direction == 'l')
        {
            this->direction = 'u';
        }
        else if (this->direction == 'r')
        {
            this->direction = 'd';
        }
        else if (this->direction == 'd')
        {
            this->direction = 'l';
        }
        else if (this->direction == 'u')
        {
            this->direction = 'r';
        }
    }
    void turnBackword()
    {
        if (this->direction == 'l')
        {
            this->direction = 'r';
        }
        else if (this->direction == 'r')
        {
            this->direction = 'l';
        }
        else if (this->direction == 'd')
        {
            this->direction = 'u';
        }
        else if (this->direction == 'u')
        {
            this->direction = 'd';
        }
    }
    void display() const
    {
        cout << this->name << " is at (" << this->row << "," << this->col << ")"
             << " towards " << this->direction;
    }

    friend istream &operator>>(istream &cin,robot &r){
        string a;
        int b,c;
        char d;
        cout<<"\nEnter the name\n";
        cin>>a;
        cout<<"\nEnter the x-location\n";
        cin>>b;
        cout<<"\nEnter the y-location\n";
        cin>>c;
        cout<<"\nEnter the direction\n";
        cin>>d;
        r.setRobot(a, b, c, d);
        return cin;
    }

private:
    string name;
    int row, col;
    char direction; // u(up), d(down), l(left), r(right) on Cartesian plane
};

int main()
{
    robot robo[4];
    robo[0].setRobot("R", 0, 2, 'u');
    robo[1].setRobot("S", 44, 22, 'l');
    robo[2].setRobot("T", 32, 21, 'd');
    robo[3].setRobot("Q", 0, 0, 'r');



    //Alternative
    // cin>>robo[0];
    // cin>>robo[1];
    // cin>>robo[2];
    // cin>>robo[3];

    int x[4], y[4], reqx[4], reqy[4], d[4];
    char dirx[4], diry[4], dx[4], dy[4];

    //specifing the destination coordinates
    x[0] = 0;
    y[0] = 99;
    x[1] = 99;
    y[1] = 99;
    x[2] = 0;
    y[2] = 0;
    x[3] = 99;
    y[3] = 0;
    int i = 0;

    //The program will automatically identify the direction towards the destination
    while (i < 4)
    {
        reqx[i] = x[i] - robo[i].getLocationX();
        if (reqx[i] >= 0)
        {
            dirx[i] = 'r';
        }
        else if (reqx[i] < 0)
        {
            dirx[i] = 'l';
        }

        reqy[i] = y[i] - robo[i].getLocationY();
        if (reqy[i] >= 0)
        {
            diry[i] = 'u';
        }
        else if (reqy[i] < 0)
        {
            diry[i] = 'd';
        }
        i++;
    }

    //Turn wise zigzag movement of each robot
    i = 0;

    while (1)
    {

        if (i == 4)
        {
            i = 0;
            system("CLS");
        }

        //ZIG
        robo[i].setDirection(dirx[i]);
        if (robo[i].getLocationX() != x[i])
        {
            robo[i].takeStep();
        }
        else
        {

            dx[i] = 'd';
        }

        //ZAG
        robo[i].setDirection(diry[i]);
        if (robo[i].getLocationY() != y[i])
        {
            robo[i].takeStep();
        }
        else
        {

            dy[i] = 'd';
        }

        if (dx[0] == 'd' && dx[1] == 'd' && dx[2] == 'd' && dx[3] == 'd')
        {
            if (dy[0] == 'd' && dy[1] == 'd' && dy[2] == 'd' && dy[3] == 'd')
            {
                break;
            }
        }

        robo[i].display();
        cout << endl;

        i++;
    }
    system("CLS");
    //Displaying the robots using separate loop
    for (int i = 0; i < 4; i++)
    {
        robo[i].display();
        cout << endl;
    }
}
