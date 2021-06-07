/*Name: Shukhratov Bekhzod U2010259
Program Statement: Lab Assignment 5   */

#include<iostream>
using namespace std;
void introdisplay()// to display the following;
{
	cout << "Which operation you want to perform? " << endl << endl;
	cout << "1 for Displaying Time" << endl;
	cout << "2 for Displaying Time in Seconds" << endl;
	cout << "3 for Increment Seconds" << endl;
	cout << "4 for Decrement Minutes" << endl;
	cout << "5 for Exit" << endl;
}
class DayTime// class of type daytime
{
private:
	int hour, minute, second;// private variables
public:
	DayTime()// constrcutor, sets default
	{
		hour = 0;
		minute = 0;
		second = 0;
	}
	int getHour(const int h)// it gets and sets value to hour
	{
		hour = h;
		return hour;
	}
	int getMinute(const int m)// this too
	{
		minute = m;
		if (minute >= 60)// if statement to convert minutes to hours if it is more that 60
		{
			hour = hour + minute / 60;
			minute = minute % 60;
		}
		return minute;
	}
	int getSecond(const int s)
	{
		second = s;
		if (second >= 60)// if statement to convert seconds to minutes if it is more that 60
		{
			minute = minute + second / 60;
			second = second % 60;
		}
		return second;
	}
	int asSeconds()// gives whole time in seconds
	{
		int asseconds;
		asseconds = hour * 3600 + minute * 60 + second;// simple formula
		return asseconds;
	}
	void displaytime()// func to display time in standard form
	{
		cout << "Time is: ";
		cout << hour << ":" << minute << ":" << second << endl << endl;
	}
	void operator++()// operator overloading
	{
		second = second + 1;// it is for incrementing
	}
	void operator--()
	{
		minute = minute - 1;// for decrementing will be used to decrement minutes
	}
};
class Dollar
{
private:
	float currency, mktrate, offrate;  // inaccessible variables
public:
	float getDOllar(float c)// it sets and gets value of currency
	{
		currency = c/offrate;
		return currency;
	}
	float getMarketSoums(float ms)// the same
	{
		currency = ms * mktrate;// value will be multiplied by market rate of dollar
		return currency;
	}
	float getOfficialSoums(float os)
	{
		currency = os * offrate;
		return currency;
	}
	void setRates()
	{
		offrate = 10600;// this will be set to the currency rates
		mktrate = 10500;
	}
	friend void operator<<(ostream& out, Dollar i);// we making operator function a friend of the class
};
void operator<<(ostream& out, Dollar i)
{
	cout << "Your soums will be: " << i.currency << " dollars" << endl;
}
int main()
{
	startingpoint:
	cout << "Type the number of program you want to check! 1 or 2" << endl;
	int l;
	cin >> l;
	switch (l)// it is easy)
	{
	case 1:///////////// first program
	{
		int h, m, s, j;
		DayTime sometime;// variable sometime is type class daytime
		cout << "First of all, input the time!" << endl;
		cout << "Hours: ";
		cin >> h;
		cout << "Minutes: ";
		cin >> m;
		cout << "Seconds: ";
		cin >> s;
		sometime.getHour(h);// we get the values of time
		sometime.getMinute(m);
		sometime.getSecond(s);
		while (true)// infinite loop to prevent unexpected exit
		{
			introdisplay();
			cin >> j;
			switch (j)
			{
			case 1://Display time
			{
				sometime.displaytime();
				break;
			}
			case 2://asSeconds
			{
				cout << "Time in seconds is: " << sometime.asSeconds() << " sec" << endl;
				break;
			}
			case 3://Increment Seconds
			{
				++sometime;// overloading ++ operation
				break;
			}
			case 4://Decrement Minutes
			{
				--sometime;
				break;
			}
			case 5:
			{
				goto startingpoint;// In my program, goto works fine, even though many say it is not good.
			}
			}
		}
	}
	case 2:////////////////////////////////////////second program
	{
		Dollar somemoney;// somemoney is a variable of type dollar class
		somemoney.setRates();// we firstly should set the values. otherwise, some garbage number will appear
		cout << "Input your Currency! 1 for Dollar, 2 for Soums" << endl;
		int k;
		float money;
		cin >> k;
		cout << "Now input how much is your money!" << endl;
		cin >> money;
		if (k == 1)// I could use swith, too. I wanted to include if statement in my program, too
		{
			cout << "Officially it is: " << somemoney.getMarketSoums(money) << " soums" << endl;// gives in two options. official
			cout << "In the market it would be: " << somemoney.getOfficialSoums(money) << " soums" << endl;// or marketrate
		}
		else if (k == 2)
		{
			somemoney.getDOllar(money);
			cout << somemoney;// Here I overloaded << operator
		}
		else
			break;
	}
	default:
	{
		goto startingpoint;
	}
	}
	return 0;// Thanks for watching. Please Subscribe:)
}