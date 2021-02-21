#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class List
{
private:
    const int MAX_SPARE_ENTRIES = 100;
    int arraySize;
    int listSize;
    double *array;

    void deallocArray()
    {
        delete[] array;
        array = NULL;
        arraySize = listSize = 0;
    }

public:
    int getMAX_SPARE_ENTRIES() const
    {
        return MAX_SPARE_ENTRIES;
    }

    int getArraySize() const
    {
        return arraySize;
    }

    // now you can set the array size of list at runtime and it won't cause data loss
    void setArraySize(int as)
    {
        if (as > listSize)
        {
            this->arraySize = as + MAX_SPARE_ENTRIES;
            double *arrayy = new double[this->arraySize];
            for (int i = 0; i < this->listSize; i++)
            {
                arrayy[i] = this->array[i];
            }
            this->array = arrayy;
        }
        else
        {
            this->arraySize = as;
        }
    }

    int getListSize() const
    {
        return listSize;
    }

    void setListSize(int ls) //I have used it to increase list size when an element is inserted
    {
        // if (ls < listSize)
        listSize = ls;
    }

    double getArrayElement(int i) const
    {
        return array[i];
    }
    void setArrayElement(int i, double d)
    {
        array[i] = d;
    }

    ~List()
    {
        deallocArray();
    }
    List()
    {
        arraySize = MAX_SPARE_ENTRIES;
        listSize = 0;
        array = new double[MAX_SPARE_ENTRIES];
    }
    List(int size)
    {
        arraySize = size + MAX_SPARE_ENTRIES;
        listSize = 0;
        array = new double[arraySize];
    }
    List(int size, double initvalue)
    {
        arraySize = size + MAX_SPARE_ENTRIES;
        listSize = 0;
        array = new double[arraySize];
        for (int k = 0; k < arraySize; k++)
        {
            array[k] = initvalue;
        }
    }

    List(const List &lst)
    {
        arraySize = lst.arraySize;
        listSize = lst.listSize;
        array = new double[lst.arraySize];
        for (int k = 0; k < listSize; k++)
        {
            array[k] = lst.array[k];
        }
    }

    List operator=(const List &lst)
    {
        deallocArray();
        arraySize = lst.arraySize;
        listSize = lst.listSize;

        array = new double[lst.arraySize];
        for (int k = 0; k < listSize; k++)
        {
            array[k] = lst.array[k];
        }
    }
    void makeListEmpty()
    {
        listSize = 0;
    }

    void showList() const
    {
        for (int k = 0; k < listSize; k++)
        {
            cout << array[k] << " ";
        }
    }

    void append(double vl)
    {
        if (!this->isFull())
        {
            array[listSize] = vl;
            listSize++;
        }
        else
            throw 0;
    }

    bool operator==(const List &lst) const
    {
        if (this->listSize != lst.listSize)
        {
            return false;
        }
        for (int k = 0; k < listSize; k++)
        {
            if (this->array[k] != lst.array[k])
            {
                return false;
            }
        }
        return true;
    }

    bool search(double vl) const
    {
        for (int k = 0; k < listSize; k++)
        {
            if (this->array[k] == vl)
            {
                return true;
            }
        }
        return false;
    }

    void removeAt(int ind)
    {
        if (ind >= listSize)
            throw 0;
        else
        {
            for (int k = ind; k < listSize; k++)
            {
                array[k] = array[k + 1];
            }
            listSize--;
        }
    }

    void removeFirstMatch(double vl)
    {
        int ind = indexOfFirstMatch(vl);
        removeAt(ind);
    }
    bool isFull()
    {
        return this->getListSize() == this->getArraySize();
    }
    int indexOfFirstMatch(double val)
    {
        int i;
        for (i = 0; i < this->listSize; i++)
        {
            if (search(val))
            {
                if (this->array[i] == val)
                {
                    break;
                }
            }
        }
        return i;
    }

    void setArray(int MAX_SPARE_ENTRIES)
    {
        if(MAX_SPARE_ENTRIES>0){
          this->array = new double[MAX_SPARE_ENTRIES];
        }
        else{
            this->array = NULL;
        }
        
    }

    friend void disposeList(List &l);
};

void append(List &, double);
void initializeList(List &);
void showList(const List &);
void makeListEmpty(List &l);
bool isEmpty(const List &);
bool isFull(const List &);
bool search(const List &, double);

int countOf(const List &, double);

int indexOfFirstMatch(const List &, double);
int indexOfLastMatch(const List &, double);
int indexOfMatchAfter(const List &, double, int);

void removeAt(List &, int);
void removeFirstMatch(List &, double);
void removeAll(List &, double);

void insertAt(List &, double, int);
void insertAtbegining(List &, double);
void insertBefore(List &, double, double);
void insertAfter(List &, double, double);

void updateAt(List &, double, int);
void updateFirstMatch(List &, double, double);
void updateAll(List &, double, double);

List join(const List &, const List &);
List subList(const List &, int, int);

// following can only be made for numbers
double max(const List &);
double min(const List &);
double sum(const List &);
double product(const List &);
double mean(const List &);

List wholeNumbers(const List &);

//////////////////////////////////////////////////

int main()
{

    List nums;
    initializeList(nums);

    append(nums, 3.45);
    append(nums, 2.72);
    append(nums, 3.91);
    append(nums, 2.00);
    append(nums, 2.75);
    append(nums, 2.25);
    append(nums, 3.31);
    append(nums, 3.83);
    append(nums, 2.43);
    append(nums, 1.83);
    //makeListEmpty(nums);
    append(nums, 2.94);
    append(nums, 3.65);
    append(nums, 2.98);

    showList(nums);

    disposeList(nums);
    return 0;
}

//////////////////////////////////////////////////

void initializeList(List &l)
{
    l.setArray(l.getMAX_SPARE_ENTRIES());
    l.setArraySize(l.getMAX_SPARE_ENTRIES());
    l.setListSize(0);
}

void disposeList(List &l)
{
    l.deallocArray();
    l.setArray(-1);
    l.setListSize(0);
    l.setArraySize(0);
}

void makeListEmpty(List &l)
{
    l.setListSize(0);
}

void showList(const List &lst)
{
    for (int j = 0; j < lst.getListSize(); j++)
        cout << fixed << setprecision(2) << lst.getArrayElement(j) << " ";
    cout << endl;
}

void append(List &l, double d)
{
    if (isFull(l))
        throw -1;
    l.setArrayElement(l.getListSize(), d);
    l.setListSize(l.getListSize() + 1);
}

bool isEmpty(const List &l)
{
    return l.getListSize() == 0;
}

bool isFull(const List &l)
{
    return l.getListSize() == l.getArraySize();
}

bool equal(const List &l1, const List &l2)
{
    return l1 == l2;
    // return true, if l1 and l2 are exactly same upto arraySize
}

bool search(const List &l, double d)
{
    return l.search(d);
    // return true if d is somewhere in List l (upto arraySize)
}

int countOf(const List &l, double d)
{
    if (!l.search(d))
    {
        throw -1;
    }
    int count = 0;
    for (int i = 0; i < l.getListSize(); i++)
    {
        if (l.getArrayElement(i) == d)
        {
            count++;
        }
    }
    return count;

    // return count of values matches d in list l (upto arraySize)
}

int indexOfFirstMatch(const List &l, double d)
{
    int i;
    for (i = 0; i < l.getListSize(); i++)
    {
        if (l.search(d))
        {
            if (l.getArrayElement(i) == d)
            {
                break;
            }
        }
    }
    return i;
}

int indexOfLastMatch(const List &l, double d)
{
    int z;
    for (int i = 0; i < l.getListSize(); i++)
    {
        if (l.search(d))
        {
            if (l.getArrayElement(i) == d)
            {
                z = i;
            }
        }
    }
    return z;
}

int indexOfMatchAfter(const List &l, double a, int b)
{
    if (b < l.getListSize())
    {
        int i;
        for (i = b; i < l.getListSize(); i++)
        {
            if (l.getArrayElement(i) == a)
            {
                break;
            }
        }
        return i;
    }
    else
    {
        throw -1;
    }
}

void removeAt(List &l, int a)
{
    l.removeAt(a);
}

void removeFirstMatch(List &l, double a)
{
    l.removeFirstMatch(a);
}

void removeAll(List &l, double d)
{
    while (1)
    {
        if (l.search(d))
        {
            l.removeFirstMatch(d);
        }
        else
        {
            break;
        }
    }
}

void insertAt(List &l, double d, int a)
{
    //   l.setArrayElement(i,d);

    for (int i = (l.getListSize() - 1); i >= a; i--)
    {
        l.setArrayElement(i + 1, l.getArrayElement(i));
    }
    l.setArrayElement(a, d);
    l.setListSize(l.getListSize() + 1);
}

void insertAtbegining(List &l, double d)
{
    int a = 0;
    for (int i = (l.getListSize() - 1); i >= a; i--)
    {
        l.setArrayElement(i + 1, l.getArrayElement(i));
    }
    l.setArrayElement(a, d);
    l.setListSize(l.getListSize() + 1);
}

void insertBefore(List &l, double a, double b) // insert a before b
{
    int d = l.getListSize();
    for (int i = 0; i < d; i++)
    {
        if (l.getArrayElement(i) == b)
        {
            insertAt(l, a, i);
            i++;
        }
    }
}

void insertAfter(List &l, double a, double b) //insert a after b
{
    int d = l.getListSize();
    for (int i = 0; i < d; i++)
    {
        if (l.getArrayElement(i) == b)
        {
            insertAt(l, a, i + 1);
        }
    }
}

void updateAt(List &l, double a, int i)
{
    l.setArrayElement(i, a);
}

void updateFirstMatch(List &l, double a, double b) //update first match a with b
{
    for (int i = 0; i < l.getListSize(); i++)
    {
        if (l.getArrayElement(i) == a)
        {
            l.setArrayElement(i, b);
            break;
        }
    }
}

void updateAll(List &l, double a, double b)
{
    for (int i = 0; i < l.getListSize(); i++)
    {
        if (l.getArrayElement(i) == a)
        {
            l.setArrayElement(i, b);
        }
    }
}

List join(const List &a, const List &b)
{
    List ret;
    ret.setArraySize(a.getArraySize() + b.getArraySize());
    for (int i = 0; i < a.getListSize(); i++)
    {
        ret.append(a.getArrayElement(i));
    }

    for (int i = 0; i < b.getArraySize(); i++)
    {
        ret.append(b.getArrayElement(i));
    }
    ret.setListSize(a.getListSize() + b.getListSize());
    return ret;
}

List subList(const List &l, int s, int e)
{
    List ret;
    for (int i = s; i <= e; i++)
    {
        ret.append(l.getArrayElement(i));
    }
    return ret;
}

// following can only be made for numbers
double max(const List &l)
{
    double max;
    for (int i = 0; i < l.getListSize(); i++)
    {
        if (i == 0)
        {
            max = l.getArrayElement(i);
        }
        else
        {
            if (l.getArrayElement(i) > max)
            {
                max = l.getArrayElement(i);
            }
            else
            {
                continue;
            }
        }
    }
    return max;
}

double min(const List &l)
{
    double min;
    for (int i = 0; i < l.getListSize(); i++)
    {
        if (i == 0)
        {
            min = l.getArrayElement(i);
        }
        else
        {
            if (l.getArrayElement(i) < min)
            {
                min = l.getArrayElement(i);
            }
            else
            {
                continue;
            }
        }
    }
    return min;
}

double sum(const List &l)
{
    double sum = 0;
    for (int i = 0; i < l.getListSize(); i++)
    {
        sum += l.getArrayElement(i);
    }
    return sum;
}

double product(const List &l)
{
    double prod = 1;
    for (int i = 0; i < l.getListSize(); i++)
    {
        prod = prod * l.getArrayElement(i);
    }
    return prod;
}

double mean(const List &l)
{
    double sum = 0, mean;
    for (int i = 0; i < l.getListSize(); i++)
    {
        sum += l.getArrayElement(i);
    }
    mean = sum / l.getListSize();
    return mean;
}

List wholeNumbers(const List &l)
{
    List whole;
    for (int i = 0; i < l.getListSize(); i++)
    {
        whole.append(round(l.getArrayElement(i)));
    }
    return whole;
}
