/* Name: Shukhratov Bekhzod U2010259
   Program Statement: Lab Assignment 9, part 1*/
#include<iostream>
using namespace std;
class Shape// base class
{
protected:
	double width, height;
public:
	Shape(){}//default constructor
	Shape(double w, double h)//parametrized constructor
	{
		height = h;
		width = w;
	}
	void getdata()// to set the values
	{
		cout << "Input height and width" << endl;
		cin >> height >> width;
	}
	virtual void display_area() = 0// virtual pure function
	{
		cout << "The Area: " << width * height << endl;
	}
};
class Triangle:public Shape// child class Triangle inherited from Shape
{
private:
	double area;
public:
	Triangle() { area = 0; }//default constructor
	Triangle(double width, double height): Shape(width, height)// parametrized constructor 
	{
		area = (width * height) / 2;
	}
	void display_area()//displays the area
	{
		cout << "The Area:" << area << endl;
	}
};
class Circle :public Shape// child class Triangle inherited from Shape
{
private:
	double area;
public:
	Circle() { area = 0; }//default constructor
	Circle(double width, double height) : Shape(width, height)// parametrized constructor 
	{
		area = 3.14*width*width;
	}
	void display_area()//displays the area
	{
		cout << "The Area:" << area << endl;
	}
};
class Rectangle :public Shape// the same here
{
private:
	double area;
public:
	Rectangle() { area = 0; }
	Rectangle(double width, double height):Shape(width, height)
	{
		area = width * height;
	}
	void display_area()
	{
		cout << "The Area:" << area << endl;
	}
};
int main()
{
	string i;
	while (true)//to prevent accidental exit
	{
		cout << "Rectangle or Triangle or Circle? (r/t/c)" << endl;
		cout << "To exit, type exit" << endl;
		cin >> i;
		if (i == "r")
		{
			double width, height;
			cout << "Input Width" << endl;
			cin >> width;
			cout << "Input Height" << endl;
			cin >> height;
			Shape* s;// defining a pointer object
			Rectangle r(width, height);
			s = &r;// giving the adress of a obj to the pointer
			s->display_area();// calling pointer ibject's function
		}
		else if (i == "t")
		{
			double width, height;        // same here
			cout << "Input Base" << endl;
			cin >> width;
			cout << "Input Height" << endl;
			cin >> height;
			Shape* s1;// declaring an object
			Triangle t(width, height);// passing arguments
			s1 = &t;// equalizing the addres of a object to a pointer
			s1->display_area();
		}
		else if (i == "c")
		{
			double width;
			cout << "Input Radius" << endl;
			cin >> width;
			Shape* s2;// declaring an object
			Circle c(width, 0);// passing arguments
			s2 = &c;// equalizing the addres of a object to a pointer
			s2->display_area();
		}
		else if (i == "exit" || i == "Exit")
		{
			exit(0);
		}
	}
	system("pause");
	return 0;
}