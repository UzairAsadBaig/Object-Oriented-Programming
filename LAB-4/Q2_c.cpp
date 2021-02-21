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

private:
    string name;
    int row, col;
    char direction; // u(up), d(down), l(left), r(right) on Cartesian plane
};

int main()
{
    robot robo[6];
    robo[0].setRobot("R", 0, 2, 'u');
    robo[1].setRobot("S", 44, 22, 'l');
    robo[2].setRobot("T", 32, 21, 'd');
    robo[3].setRobot("Q", 0, 0, 'r');
    robo[4].setRobot("P", 21, 32, 'd');
    robo[5].setRobot("Z", 99, 99, 'u');

    int x = robo[2].getLocationX(), y = robo[2].getLocationY(), reqx[6], reqy[6], d[6];
    char dirx[6], diry[6], dx[6], dy[6];

    int i = 0;
    while (i < 6)
    {
        reqx[i] = x - robo[i].getLocationX();
        if (reqx[i] >= 0)
        {
            dirx[i] = 'r';
        }
        else if (reqx[i] < 0)
        {
            dirx[i] = 'l';
        }

        reqy[i] = y - robo[i].getLocationY();
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

    //Turn wise movement of each robot towards t
    int poss[6], a = 1;
    for (int i = 0; i < 6; i++)
    {
        poss[i] = 0;
    }

    i = 0;

    while (1)
    {
        if (i == 6)
        {
            i = 0;
            system("CLS");
        }

        robo[i].setDirection(dirx[i]);
        if (robo[i].getLocationX() != x)
        {
            robo[i].takeStep();
        }
        else
        {

            dx[i] = 'd';
        }

        robo[i].setDirection(diry[i]);
        if (robo[i].getLocationY() != y + (reqy[i] / 10))
        {
            robo[i].takeStep();
        }
        else
        {

            dy[i] = 'd';
        }

        if (dx[i] == 'd' && dy[i] == 'd')
        {
            if (poss[i] == 0)
            {
                poss[i] = a;
                a++;
            }

            cout << robo[i].getRobotName() << " has reached (" << robo[i].getLocationX() << "," << robo[i].getLocationY() << ")"
                 << " near T " << poss[i];
            if (poss[i] == 1)
            {
                cout << "st" << endl;
            }
            else if (poss[i] == 2)
            {
                cout << "nd" << endl;
            }
            else if (poss[i] == 3)
            {
                cout << "rd" << endl;
            }
            else
            {
                cout << "th" << endl;
            }
        }
        if (dx[0] == 'd' && dx[1] == 'd' && dx[2] == 'd' && dx[3] == 'd' && dx[4] == 'd' && dx[5] == 'd')
        {
            if (dy[0] == 'd' && dy[1] == 'd' && dy[2] == 'd' && dy[3] == 'd' && dy[4] == 'd' && dy[5] == 'd')
            {
                break;
            }
        }
        i++;
    }
}
