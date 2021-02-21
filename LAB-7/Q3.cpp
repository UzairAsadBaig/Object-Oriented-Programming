#include <iostream>

using namespace std;

class MyString
{

private:
    int SPARE_SIZE = 100;
    int arraySize;
    int stringSize;
    char *array;

    void deallocArray()
    {
        delete[] array;
        array = NULL;
        arraySize = stringSize = 0;
    }

public:
    //-----------------------------Getters/Setters---------------------------------
    int getArraySize() const
    {
        return this->arraySize;
    }
    void setArraySize(int a)
    {
        this->arraySize = a;
    }
    int getStringSize() const
    {
        return this->stringSize;
    }
    void setStringSize(int a)
    {
        this->stringSize = a;
    }
    char getArrayChar(int a) const
    {
        return this->array[a];
    }
    void setArrayChar(char b, int a)
    {
        this->array[a] = b;
    }

    //--------------------Constructor/Destructor-----------------
    MyString()
    {
        this->setArraySize(this->SPARE_SIZE);
        this->setStringSize(0);
        this->array = new char[this->getArraySize()];
    }
    MyString(char *b)
    {
        string a=(string)b;
        this->setArraySize(this->SPARE_SIZE);
        this->setStringSize(0);
        this->array = new char[this->getArraySize()];
        for (int i = 0; i < a.length(); i++)
        {
            append(a[i]);
        }

    }
    // MyString(string a)
    // {
    //     this->setArraySize(this->SPARE_SIZE);
    //     this->setStringSize(0);
    //     this->array = new char[this->getArraySize()];
    //     for (int i = 0; i < a.length(); i++)
    //     {
    //         append(a[i]);
    //     }

    // }
    MyString(const MyString &a)
    {
        this->setArraySize(a.getArraySize());
        this->setStringSize(a.getStringSize());
        this->array = new char[this->getArraySize()];
        for (int i = 0; i < this->getStringSize(); i++)
        {
            this->setArrayChar(a.getArrayChar(i), i);
        }
    }
    ~MyString()
    {
        deallocArray();
    }

    //----------------------Input/Output Operators---------------------
    friend istream &operator>>(istream &bin, MyString &m)
    {
        char a;
        while (1)
        {
            a = getchar();

            if (a == '\n' || a == '\r')
            { //work for both windows and mac
                break;
            }
            m.append(a);
        }

        return bin;
    }
    friend ostream &operator<<(ostream &bout, MyString m)
    {
        for (int i = 0; i < m.getStringSize(); i++)
        {
            bout << m.getArrayChar(i);
        }
        return bout;
    }

    //-----------------------Equal Operator-------------------
   
    void operator=(const MyString &a)
    {
        deallocArray();
        setArraySize(a.getArraySize());
        setStringSize(a.getStringSize());
        this->array = new char[this->getArraySize()];
        for (int i = 0; i < getStringSize(); i++)
        {
            setArrayChar(a.getArrayChar(i), i);
        }
    }
     void operator=(string a)
    {
        this->setArraySize(this->SPARE_SIZE);
        this->setStringSize(0);
        this->array = new char[this->getArraySize()];
        for (int i = 0; i < a.length(); i++)
        {
            append(a[i]);
        }
    }
    

    //----------------------String Concatenation---------------
    MyString operator+(const MyString &a)
    {
        MyString ret;
        ret.setArraySize(a.getArraySize() + getArraySize());
        for (int i = 0; i < getStringSize(); i++)
        {
            ret.append(getArrayChar(i));
        }

        for (int i = 0; i < a.getStringSize(); i++)
        {
            ret.append(a.getArrayChar(i));
        }

        return ret;
    }
    MyString operator+(string a)
    {
        MyString ret;
        ret.setArraySize(a.length() + getArraySize());
        for (int i = 0; i < getStringSize(); i++)
        {
            ret.append(getArrayChar(i));
        }

        for (int i = 0; i < a.length(); i++)
        {
            ret.append(a[i]);
        }

        return ret;
    }

    //    -----------------------Append Function---------------------
    void append(char a)
    {
        this->setArrayChar(a, this->getStringSize());
        this->stringSize++;
    }

    //    -----------------------Sub-String Function---------------------
    MyString substr(int a, int b)
    {

        if (b <= getStringSize())
        {
            MyString ret;
            for (int i = a; i < b; i++)
            {
                ret.append(getArrayChar(i));
            }
            return ret;
        }
        else{
            throw 0;
        }
    }

    //---------------------------[] operator ------------------------
    char operator[](int i){
        return this->getArrayChar(i);
    }
};


    //    -----------------------Length Function---------------------
int length(MyString s)
{
    return s.getStringSize();
}

    //    -----------------------Show String Function---------------------
void showString(MyString m)
{
    for (int i = 0; i < m.getStringSize(); i++)
    {
        cout << m.getArrayChar(i);
    }
}

int main()
{
   MyString a="Hello";
   cout<<a;
}