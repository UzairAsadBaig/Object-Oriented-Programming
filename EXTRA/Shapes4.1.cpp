// square is inherited from rectangle, which is inheriting shape. 
//Note Rectangle's output for square, it will be explained later
// nothing else is changed

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

		void setPoint2D(float x1,float y1)
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
enum color{red,blue,yellow,orange,black,white,green,purple,pink};

//SHAPE
class Shape
{
	protected:
		int borderWidth;
		color borderColor;
		color fillColor;
		string name;
		string type;
	public:

		~Shape()
		{
			cout << "Shape destroyed" << name << endl;
		}

		//GETTERS
		int getBorderWidth()
		{
			return borderWidth;
		}
		color getBorderColor()
		{
			return borderColor;
		}
		color getFillColor()
		{
			return fillColor;
		}
		string getName()
		{
			return name;
		}
		string getType()
		{
			return type;
		}
		//SETTERS
		void setBorderWidth(int bW)
		{
			borderWidth=bW;
		}
		void setBorderColor(color bC)
		{
			borderColor=bC;
		}
		void setFillColor(color fC)
		{
			fillColor=fC;
		}
		void setName(string n)
		{
			name=n;
		}
		void setType(string t)
		{
			type=t;
		}
		void setShape(string n,string t,int bW,color bC,color fC)
		{
			name=n;
			type=t;
			borderWidth=bW;
			borderColor=bC;
			fillColor=fC;
		}
		//CONSTRUCTORS
		Shape(string n,string t,int bW,color bC,color fC)
		{
			name=n;
			type=t;
			borderWidth=bW;
			borderColor=bC;
			fillColor=fC;
		}
		Shape()
		{
			name="Unknown";
			type="Unknown";
			borderWidth=0;
			borderColor=red;
			fillColor=red;
		}
		//TO STRING
		string toString()
		{
			string s;
			ostringstream oss;
			oss <<"Name:"<<getName();
			oss <<";Type:"<<getType();
			oss <<";Border-width:"<<getBorderWidth();
			oss <<";Border-Color:"<<getBorderColor();
			oss <<";Fill-Color:"<<getFillColor();
			s = oss.str();
			return s;
		}
};

//RECTANGLE
class Rectangle : public Shape
{
	protected:
		Point2D topLeft;
		float ln;
		float wid;
	public:

		~Rectangle()
		{
			cout << "Rectangle destroyed" << endl;
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
		void setRectangle(string n,string t,int bW,color bC,color fC, Point2D p,float l,float w)
		{
			Shape::setShape(n,t,bW,bC,fC);
			topLeft.setX(p.getX());
			topLeft.setY(p.getY());
			ln=l;
			wid=w;
		}
		//CONSTRUCTORS
		Rectangle(string n,string t,int bW,color bC,color fC, Point2D &p,float l,float w) : Shape(n, t, bW, bC, fC)
		{
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
			oss <<" and width "<<getWid();
			s = oss.str();
			return s;
		}
		//METHOD TO AREA
		float area()
		{
			return ln*wid;
		}
};

class Square : public Rectangle
{
      public:
		~Square()
		{
			cout << "Square destroyed" << endl;
		}

		//Constructor
		Square(string n,string t,int bW,color bC,color fC, Point2D &p,float len) : Rectangle(n,t,bW,bC,fC, p,len,len)
		{
		}
};

class Circle  : public Shape
{
	protected:
		Point2D centre;
		float rad;
	public:

		~Circle()
		{
			cout << "Circle destroyed" << endl;
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
		void setCircle(string n,string t,int bW,color bC,color fC, Point2D c,float r)
		{
			Shape::setShape(n,t,bW,bC,fC);
			centre = c;
			rad=r;
		}
		//CONSTRUCTORS
		Circle(string n,string t,int bW,color bC,color fC, Point2D &p,float r) : Shape(n, t, bW, bC, fC)
		{
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
			oss <<" of radius "<<getRad();
			s = oss.str();
			return s;
		}
		//METHOD TO AREA
		float area()
		{
			return PI * rad * rad;
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


	Square *s1 = new Square("S1", "Square", 1, blue, pink, o, 6);
	cout << "Square created with a point composed" << endl;
	Rectangle *r1 = new Rectangle("R2", "Rectangle", 1, yellow, red, o, 42, 23);
	cout << "Rectangle created with a point composed" << endl;
	Circle *c1 = new Circle("C1", "Circle", 5, red, green, o, 8);
	cout << "Circle created with a point composed" << endl;
	Rectangle *r2 = new Rectangle("R3", "Rectangle", 0, blue, pink, o, 12, 6);
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
	c->addShape(s1);
	cout << "Square is aggregated in canvas" << endl;
	c->addShape(r2);
	cout << "Rectangle is aggregated in canvas" << endl;

	cout << endl;
	c->display();
	cout << endl;

	delete c;
	cout << "Canvas deleted but rectangle in still exists" << endl;

	delete r1;
	cout << "Rectangle deleted and composed point too" << endl;
	delete c1;
	cout << "Circle deleted and composed point too" << endl;
	delete s1;
	cout << "Square deleted and composed point too" << endl;
	delete r2;
	cout << "Rectangle deleted and composed point too" << endl;
	delete c2;
	cout << "Circle deleted and composed point too" << endl;

	cout << endl << endl << "end of main which will delete Point2D o(2,6)" << endl;
	return 0;
}

