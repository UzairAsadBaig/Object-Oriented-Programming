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

        this->row = v;
    }
    int getLocationY() const
    {
        return this->col;
    }
    void setLocationY(int v)
    {
        this->col = v;
    }
    char getDirection() const
    {
        return this->direction;
    }
    void setDirection(char d)
    {
        this->direction = d;
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
}
