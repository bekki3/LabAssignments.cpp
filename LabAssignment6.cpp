#include<iostream>
using namespace std;
class Rectangle
{
private:
	double length, breadth;//variables as usual
public:
	Rectangle()//initialization, constuctor
	{
		length = 0;
		breadth = 0;
	}
	void setLength(double length)//these both to set the values
	{
		this->length=length;
	}
	void setBreadth(double breadth)
	{
		this->breadth = breadth;
	}
	double getArea()// simple double vlaue returning func
	{
		return breadth * length;
	}
	void display(string);//we saying that there is a func
	Rectangle operator+(Rectangle c)// overloading the binary + operator
	{
		Rectangle temp;
		temp.length = length + c.length;
		temp.breadth = breadth + c.breadth;
		return temp;
	}
};
void Rectangle::display(string s)// declaring the func
{
	cout << "The sides of the "<<s<<" rectangle is: " << length << ":" << breadth << endl;
	cout << "The area of the " << s << " rectangle is: " << getArea() << endl << endl;
}/////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Distance
{
	double a;//kilometer and meter no matter actually
public:
	Distance()
	{
		a = 0;//default value
	}
	Distance(double a)// parametric constructor
	{
		this->a = a;
	}
	bool operator==(Distance);
};
bool Distance::operator ==(Distance y)//overoading a bool operator. returns boolean.
{
	Distance tmp;
	tmp.a = a == y.a;
	return tmp.a;
}////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	while (true)
	{
		int j;
		cout << "Which program you want to check, 1 or 2?" << endl;
		cin>>j;
		switch (j)
		{
		case 1:
		{
			double breadth, length;// these are simple
			Rectangle shape1, shape2, BigShape;
			cout << "Enter length and breadth of the first rectangle" << endl;
			cin >> length >> breadth;
			shape1.setBreadth(breadth);
			shape1.setLength(length);
			shape1.display("1st");
			cout << "Enter length and breadth of the Second rectangle" << endl;
			cin >> length >> breadth;
			shape2.setBreadth(breadth);
			shape2.setLength(length);
			shape2.display("2nd");
			BigShape = shape1 + shape2;// here we use the overloaded + operator
			BigShape.display("Big");
			break;
		}
		case 2:
		{
			double aa, bb;
			string str1, str2;
			cout << "Input the first distance: ";
			cin >> aa;
			cout << "Is it in meters? (Y/N)" << endl;
			cin >> str1;
			if (str1 == "n")
			{
				aa = aa * 1000;// this is to convert to meters firstly
			}
			cout << "Input the second distance: ";
			cin >> bb;
			cout << "Is it in meters? (Y/N)" << endl;
			cin >> str2;
			if (str2 == "n")
			{
				bb = bb * 1000;
			}
			Distance o1(aa), o2(bb);// passing the given distance to the func above then overloading the bool operator
			if (o1==o2)// if its true, then: 
			{
				cout << "They are equal" << endl;
			}
			else// otherwise
			{
				cout << "They are NOT equal" << endl;
				cout << "The difference of distances is " << aa - bb <<" meters"<< endl;
			}
		}
		}
	}
	system("pause");
	return 0;
}