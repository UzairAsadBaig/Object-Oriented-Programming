#include <iostream>

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
            else if (this->direction == 'b')
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

    int r = 0;
    while (r < 6)
    {
        robo[r].display();
        cout << endl;
        r++;
    }

    //LOL THE CODE BELOW WAS JUMPING THEM 4 TIMES THEIR X OR Y VALUE ON THE BOARD THATS WHY I COMMENTED IT

    // int i = 0, jump;
    // while (i < 6)
    // {

    //     if (robo[i].getDirection() == 'u' || robo[i].getDirection() == 'd')
    //     {
    //         jump = 4 * robo[i].getLocationY();
    //         int j = robo[i].getLocationY();
    //         while (j < jump)
    //         {
    //             robo[i].takeStep();
    //             j++;
    //         }
    //     }
    //     else if (robo[i].getDirection() == 'l' || robo[i].getDirection() == 'r')
    //     {
    //         jump = 4 * robo[i].getLocationX();
    //         int j = robo[i].getLocationX();
    //         while (j < jump)
    //         {
    //             robo[i].takeStep();
    //             j++;
    //         }
    //     }
    //     i++;
    // }

    //NOW SIMPLY JUMPING EACH ROBOT 4 STEPS IN THEIR PARTICULAR
    int jump = 4;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < jump; j++)
        {
            robo[i].takeStep();
        }
    }

    cout << "\nAfter jumping 4 times in their direction on the board\n\n";
    int z = 0;
    while (z < 6)
    {
        robo[z].display();
        cout << endl;
        z++;
    }
}
