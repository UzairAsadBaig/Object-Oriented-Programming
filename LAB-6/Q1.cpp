#include <iostream>
#include <fstream>

using namespace std;

class Queue
{
private:
    // member variables
     int lengthA = 100;
    int listA;
    string *array;

public:
    // member functions

    // to initialize Queue object to store sufficient values
    Queue()
    {
        this->array = new string[this->lengthA];
        listA = 0;
    }

    // return true if queue is empty
    bool isEmpty()
    {
        return listA == 0;
    }

    // to add person in a queue
    void enQueue(string person)
    {
        this->array[this->listA] = person;
        this->listA++;
    }

    // to remove a person from queue and return it
    string deQueue()
    {
        if (listA != 0)
        {
            string ret = this->array[0];
            for (int i = 0; i < this->listA; i++)
            {
                this->array[i] = this->array[i + 1];
            }
            this->listA--;
            return ret;
        }
        else
        {
            return "The queue is empty";
        }
    }

    // to print queue in order
    void printQueue()
    {
        if (listA != 0)
        {

            for (int i = 0; i < this->listA; i++)
            {
                cout << this->array[i] << endl;
            }
        }
        else
        {
            cout << "\nThe queue is empty\n";
        }
    }

    string serving()
    {
        return this->array[0];
    }
};

int main()
{

    Queue bCounter;
    ofstream fout;
    fout.open("Bank_Counter.txt");
    int ran, i = 0;
    string name;
    while (1)
    {
        ran = rand();
        ifstream readF;
        readF.open("Lab-06-Fall19-OOP-BSEF19-persons.txt");
        if (ran % 3 == 0 || ran % 13 == 0 || ran % 47 == 0 || ran % 763 == 0)
        {
            for (int j = 0; j < ran % 1536; j++)
            {
                getline(readF, name);
            }

            bCounter.enQueue(name);
            cout << name << " has arrived and entered in the queue at time " << i << endl;
            fout << name << " has arrived and entered in the queue at time " << i << endl;
            i++;
            continue;
        }

        if (bCounter.isEmpty())
        {
            cout << "Queue is empty at time " << i << endl;
            fout << "Queue is empty at time " << i << endl;
            i++;
            continue;
        }

        if (ran % 5 == 0 || ran % 11 == 0 || ran % 31 == 0 || ran % 161 == 0 || ran % 2107 == 0)
        {
            cout << bCounter.deQueue() << " got free at time " << i << endl;
            fout << bCounter.deQueue() << " got free at time " << i << endl;
        }

        cout << bCounter.serving() << " is being served at time " << i << endl;
        fout << bCounter.serving() << " is being served at time " << i << endl;

        i++;
    }
}