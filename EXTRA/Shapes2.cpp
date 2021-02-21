// Circle class is added and Canvas is modified to accomodate it

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
	{return x;}
	float getY()
	{return y;}
	//SETTERS
	void setX(float x1)
	{x=x1;}
	void setY(float y1)
	{y=y1;}

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
		x=x1;
		y=y1;
	}
	//TO STRING
	string toString()
	{
		string s;
		ostringstream oss;
		oss << "(";
		oss << getX();
		oss << ", ";
		oss << getY();
		oss << ")";
		s = oss.str();
		return s;
	}
};

//COLOR
enum color{red=0,blue,yellow,orange,black,white,green,purple,pink};

//RECTANGLE
class Rectangle
{
protected:
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
		oss <<"Rectangle at ";
		oss <<topLeft.toString();
		oss <<" of length "<<getLn();
		oss <<" and width "<<getWid()<<endl;
		s = oss.str();
		return s;
	}
	//METHOD TO AREA
	float area()
	{
		return ln*wid;
	}
};

class Circle
{
protected:
	int borderWidth;
	color borderColor;
	color fillColor;
	string name;
	string type;
	Point2D centre;
	float rad;
public:

	~Circle()
	{
		cout << "Circle destroyed" << name << endl;
	}


	//GETTERS
	Point2D getCentre()
	{
		return centre;
	}
	float getRad()
	{
		return rad;
	}
	//SETTERS
	void setCentre(Point2D p)
	{
		centre = p; 
	}
	void setRad(float r)
	{
		rad=r;
	}
	//CONSTRUCTORS
	Circle(string n,string t,int bW,color bC,color fC, Point2D &p,float r)
	{
		int borderWidth = bW;
		color borderColor = bC;
		color fillColor = fC;
		string name = n;
		string type = t;
		centre = p;
		rad=r;
	}
	//METHOD TO toString
	string toString()
	{
		string s;
		ostringstream oss;
		oss <<"Circle at ";
		oss <<centre.toString();
		oss <<" of radius "<<getRad()<<endl;
		s = oss.str();
		return s;
	}
};

//CANVAS
class canvas
{
private:
	int length;
	int width;
	Rectangle *r[100];
	int rcount;
	Circle *c[100];
	int ccount;

public:
	~canvas()
	{
		cout << "canvas deleted" << endl ;
	}
	canvas()
	{
		length = 400;
		width = 300;
		rcount = 0;
		ccount = 0;
	}
	void addShape(Rectangle *f)
	{
		r[rcount] = f;
		rcount+=1;
	}
	void addShape(Circle *f)
	{
		c[ccount] = f;
		ccount+=1;
	}
	void display()
	{
		int j=0;
		while(j<rcount)
		{
			cout << r[j]->toString() << endl;
			j+=1;
		}
		j=0;
		while(j<ccount)
		{
			cout << c[j]->toString() << endl;
			j+=1;
		}
	}

};


int main()
{
	Point2D o(2,6);


	Rectangle *r1 = new Rectangle("R1", "Rectangle", 2, blue, pink, o, 4, 3);
	cout << "Rectangle created with a point composed" << endl;
	Rectangle *r2 = new Rectangle("R2", "Rectangle", 1, yellow, red, o, 42, 23);
	cout << "Rectangle created with a point composed" << endl;
	Circle *c1 = new Circle("C1", "Circle", 5, red, green, o, 8);
	cout << "Circle created with a point composed" << endl;
	Rectangle *r3 = new Rectangle("R3", "Rectangle", 0, blue, pink, o, 12, 6);
	cout << "Rectangle created with a point composed" << endl;
	Circle *c2 = new Circle("C2", "Circle", 1, pink, red, o, 20);
	cout << "Circle created with a point composed" << endl;

	canvas *c = new canvas;
	cout << "Empty canvas created" << endl;
	c->addShape(r1);
	cout << "Rectangle is aggregated in canvas" << endl;
	c->addShape(c2);
	cout << "Circle is aggregated in canvas" << endl;
	c->addShape(c1);
	cout << "Circle is aggregated in canvas" << endl;
	c->addShape(r3);
	cout << "Rectangle is aggregated in canvas" << endl;
	c->addShape(r2);
	cout << "Rectangle is aggregated in canvas" << endl;
	
	cout << endl;
	c->display();

	delete c;
	cout << "Canvas deleted but rectangle in still exists" << endl;

	delete r3;
	cout << "Rectangle deleted and composed point too" << endl;
	delete c1;
	cout << "Circle deleted and composed point too" << endl;
	delete r1;
	cout << "Rectangle deleted and composed point too" << endl;
	delete r2;
	cout << "Rectangle deleted and composed point too" << endl;
	delete c2;
	cout << "Circle deleted and composed point too" << endl;
	
	cout << endl << endl << "end of main which will delete Point2D o(2,6)" << endl;
	return 0;
}

