#include <iostream>
#include <iomanip>

using namespace std;

class List
{
	private:
		const int MAX_SPARE_ENTRIES = 100;
		int arraySize;
		int listSize;
		double *array;
	public:
		int getMAX_SPARE_ENTRIES() const
		{
			return MAX_SPARE_ENTRIES;
		}

		int getArraySize() const
		{
			return arraySize;
		}
		/*
		void setArraySize(int as) // should not be
		{
			arraySize = as;
		}
		*/
		int getListSize() const
		{
			return listSize;
		}
		
		void setListSize(int ls) // should not be
		{
			if(ls < listSize)	 // may be
				listSize = ls;
		}
	
		void deallocArray() // private
		{
			delete[] array;
			array = NULL;
			arraySize = listSize = 0;
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
			arraySize = size;
			listSize = 0;
			array = new double[arraySize];
		}
		List(int size, double initvalue)
		{
			arraySize = size+MAX_SPARE_ENTRIES;
			listSize = 0;
			array = new double[arraySize];
			for(int k=0; k<arraySize; k++)
			{
				array[k] = initvalue;
			}
		}
		
		List(const List &lst)
		{
			arraySize = lst.arraySize;
			listSize = lst.listSize;
			array = new double[lst.arraySize];
			for(int k=0; k<listSize; k++)
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
			for(int k=0; k<listSize; k++)
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
			for(int k=0; k<listSize; k++)
			{
				cout << array[k] << " ";
			}
		}
		
		void append(double vl)
		{
			if(!isFull)
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
			for(int k=0; k<listSize; k++)
			{
				if(this->array[k] != lst.array[k])
				{
					return false;
				}
			}
			return true;
		}

		bool search(double vl) const
		{
			for(int k=0; k<listSize; k++)
			{
				if(this->array[k] == vl)
				{
					return true;
				}
			}
			return false;
		}

		void removeAt(int ind)
		{
			if(ind >= listSize)
				throw 0;
			else
			{
				for(int k=ind; k<listSize; k++)
				{
					array[k] = array[k+1];
				}
				listSize--;
			}
		}
		
		void removeFirstMatch(double vl)
		{
			int ind = indexOfFirstMatch(vl);
			removeAt(ind);
		}

};



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
	l.setArray(new double[l.getMAX_SPARE_ENTRIES()]);
	l.setArraySize(l.getMAX_SPARE_ENTRIES());
	l.setListSize(0);
}

void disposeList(List &l)
{
	l.deallocArray(l.getArray());
	l.setArray(NULL);
	l.setListSize(0);
	l.setArraySize(0);
}

void makeListEmpty(List &l)
{
	setListSize(0);
}


void showList(const List &lst)
{
	for(int j=0; j<lst.getListSize(); j++)
		cout << fixed << setprecision(2) << lst.getArrayElement(j) << " ";
	cout << endl;
}

void append(List &l, double d)
{
	if(isFull(l)) throw -1;
	l.setArrayElement(l.getListSize(), d);
	l.setListSize(l.getListSize()+1);
}


bool isEmpty(const List &l)
{
	return l.getListSize()==0;
}

bool isFull(const List &l)
{
	return l.getListSize()==l.getArraySize();
}

/*
bool equal(const List &l1, const List &l2)
{
	// return true, if l1 and l2 are exactly same upto arraySize
}

bool search(const List &l, double d)
{
	// return true if d is somewhere in List l (upto arraySize)
}


int countOf(const List &l, double d)
{
	// return count of values matches d in list l (upto arraySize)
}


int indexOfFirstMatch(const List &, double)
{
	// 
}

int indexOfLastMatch(const List &, double)
{
}

int indexOfMatchAfter(const List &, double, int)
{
}


void removeAt(List &, int)
{
}

void removeFirstMatch(List &, double)
{
}

void removeAll(List &, double)
{
}


void insertAt(List &, double, int)
{
}

void insertAtbegining(List &, double)
{
}

void insertBefore(List &, double, double)
{
}

void insertAfter(List &, double, double)
{
}


void updateAt(List &, double, int)
{
}

void updateFirstMatch(List &, double, double)
{
}

void updateAll(List &, double, double)
{
}


List join(const List &, const List &)
{
}

List subList(const List &, int, int)
{
}


// following can only be made for numbers
double max(const List &)
{
}

double min(const List &)
{
}

double sum(const List &)
{
}

double product(const List &)
{
}

double mean(const List &)
{
}


List wholeNumbers(const List &)
{
}
*/