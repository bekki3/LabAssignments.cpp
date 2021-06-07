/*
Name: Shukhratov Bekhzod U2010259
Program statement: Lab Assignment 3
*/
#include<iostream>
using namespace std;
class Box
{
private:
	double width;// width is private
public:
	friend void display(Box width);// making func dsplay a friend
	void setWidth(double width)
	{
		this->width = width;/// assigning width
	}
};
void display(Box boxx)// this is for displaying
{
	cout << "Width: " << boxx.width << endl;
}
class A// class of name A to keep x
{
	friend void swapper();// here we make this class and swapper function friends
	double x;
	void setdata()// here we set x
	{
		cout << "Enter x" << endl;// this function can be accessed by swapper function
		cin >> x;
	}
};
class B
{
	friend void swapper();
	double y; 
	void setdata()
	{
		cout << "Enter y" << endl;
		cin >> y;
	}
};
void swapper()// to call setdata functions and to swap the numbers
{
	double i;
	B bb;
	A aa;
	bb.setdata();
	aa.setdata();
	i=bb.y;
	bb.y=aa.x;
	aa.x = i;
	cout << endl << "X is equal to: " << aa.x << endl;
	cout << "Y is equal to: " << bb.y << endl;
}
int main()
{
	int j;
	while (true)// infinite loop
	{
		cout << "Which program you want to check?" << endl;
		cin >> j;
		switch (j)
		{
		case 1:
		{
			Box box;// box is type Box
			cout << "Enter width" << endl;
			double width;
			cin >> width;
			box.setWidth(width);// this will set the width
			display(box);

			break;
		}
		case 2:
		{
			B bb; A aa;
			swapper();// here we simply call this function
			break;
		}
		default:
		{
			cout << "Please type 1 or 2" << endl;
			break;
		}
		}
	}
}