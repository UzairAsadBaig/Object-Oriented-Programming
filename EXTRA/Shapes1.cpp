#include<iostream>
#include<sstream>
#include<cstring>
#include<string>

#define PI 3.14
using namespace std;

//POINT
class Point2D
{
private:
	float x;
	float y;
public:

	~Point2D()
	{
		cout << "point destroyed (" << x << "," << y << ")" << endl;
	}


	//GETTERS
	float getX()
	{
		return x;
		}
	float getY()
	{
		return y;
		}
	//SETTERS
	void setX(float x1)
	{
		this->x=x1;
		}
	void setY(float y1)
	{
		this->y=y1;
		}

	void set(float x1,float y1)
	{
		x=x1;
		y=y1;
	}
	//CONSTRUCTORS
	Point2D()
	{
		x=0.0f;
		y=0.0f;
	}
	Point2D(float x1,float y1)
	{
		this->x=x1;
		this->y=y1;
	}
	//TO STRING
	string toString()
	{
		string s;
		ostringstream oss;
		oss << getX();
		oss << ", ";
		oss << getY()<<endl;
		s = oss.str();
		return s;
	}
};

//COLOR
enum color{red=0,blue,yellow,orange,black,white,green,purple,pink};

//RECTANGLE
class Rectangle
{
private:
	int borderWidth;
	color borderColor;
	color fillColor;
	string name;
	string type;
	Point2D topLeft;
	float ln;
	float wid;
public:

	~Rectangle()
	{
		cout << "Rectangle destroyed" << name << endl;
	}


	//GETTERS
	Point2D getTopLeft()
	{
		return topLeft;
	}
	float getLn()
	{
		return ln;
	}
	float getWid()
	{
		return wid;
	}
	//SETTERS
	void setTopLeft(Point2D p)
	{
		topLeft.setX(p.getX());
		topLeft.setY(p.getY());
	}
	void setLn(float l)
	{
		ln=l;
	}
	void setWid(float w)
	{
		wid=w;
	}
	//CONSTRUCTORS
	Rectangle(string n,string t,int bW,color bC,color fC, Point2D &p,float l,float w)
	{
		int borderWidth = bW;
		color borderColor = bC;
		color fillColor = fC;
		string name = n;
		string type = t;
		topLeft = p;
		ln=l;
		wid=w;
	}
	//METHOD TO toString
	string toString()
	{
		string s;
		ostringstream oss;
		oss <<"Rectangle Point::";
		oss <<"X-axis:"<<topLeft.getX();
		oss <<";Y-axis:"<<topLeft.getY();
		oss <<";Length:"<<getLn();
		oss <<";Width:"<<getWid()<<endl;
		s = oss.str();
		return s;
	}
	//METHOD TO AREA
	float area()
	{
		return ln*wid;
	}
};

//CANVAS
class canvas
{
private:
	int length;
	int width;
	Rectangle *s[100]; // Aggregation
	int count;

public:
	~canvas()
	{
		cout << "canvas deleted" << endl ;
	}
	canvas()
	{
		length = 400;
		width = 300;
		count = 0;
	}
	void addShape(Rectangle *f)
	{
		s[count] = f;
		count+=1;
	}
	void display()
	{
		int j=0;
		while(j<count)
		{
			cout << s[j]->toString() << endl;
			j+=1;
		}
	}

};




int main()
{
	Point2D x(2,6);
	Point2D y(3,6);
	Point2D z(4,6);
	Point2D w(5,6);


	Rectangle *r1 = new Rectangle("R1", "Rectangle", 2, blue, pink, x, 4, 3);
	Rectangle *r2 = new Rectangle("R1", "Rectangle", 2, blue, pink, y, 4, 3);
	Rectangle *r3 = new Rectangle("R1", "Rectangle", 2, blue, pink, z, 4, 3);
	Rectangle *r4 = new Rectangle("R1", "Rectangle", 2, blue, pink, w, 4, 3);
	cout << "Rectangle created with a point composed" << endl;

	canvas *c = new canvas;
	cout << "Empty canvas created" << endl;
	c->addShape(r1);
	c->addShape(r3);
	c->addShape(r4);
	c->addShape(r2);
	cout << "Rectangle is aggregated in canvas" << endl;

	cout << endl;
	c->display();

	delete c;
	cout << "Canvas deleted but rectangle still exists" << endl;
	cout << "============================================" << endl << endl;

	delete r1;
	delete r2;
	delete r3;
	delete r4;
	cout << "Rectangle deleted and composed point too" << endl;

	cout << endl << endl << "end of main which will delete Point2D o(2,6)" << endl;
	return 0;
}

