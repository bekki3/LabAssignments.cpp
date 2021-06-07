/*Name: Shukhratov Bekzhod 
  Student ID: U2010259
  Program statement: Week11Assignment.
  1. Calculate the x in the power of y using recursion
  2. Find sum of natural numbers using recursion 1+2+3+4...n
  3. Fabonacci series
  4. To find GCD of two numbers*/

#include<iostream>//header file
using namespace std;
int pow(int x, int y)// function to find power of a number
{
	if (y == 0)// if statement. it will print 1 if the power is 0
	{
		return 1;
	}
	else if (y == 1)//prints the given number if power is 1
	{
		return x;
	}
	else
	{
		return x * pow(x, y - 1);//every time when function calls itself, x multiplies by itself and value of pow decreases untill 0
	}
}

int summ(int n)// function of type int to find sum of natural series
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n + summ(n - 1);// every time, number will be added to a previous number
	}
}
int febonacci(int m)// function to find febonacci series
{
	
	if (m == 1 || m == 2)// in febonacci, 1st and 2nd numbers are equal to 1
	{
		return 1;
	}
	else
	{
		return febonacci(m-2) + febonacci(m-1);// this will return sum of two previous numbers

	}
}
int GCD(int x, int y)// function of type int to find Greatest Common Devisor
{
	if (x == y)// GCD of equal numbers is equal to those numbers
	{
		return y;
	}
	else if (y == 0)// if one of two numbers equals to 0, then GCD equals 0
	{
		return 0;
	}
	else if (x == 0)
		return 0;
	else if (x > y)// if 1st number is more than 2nd, it will be substracted by the second or vice versa untill they are equal
	{
		return GCD(x - y, y);
	}
	else
	{
		return GCD(x, y - x);
	}
}
int main()
{
	int i;// i is int type because choices are integers
	startingpoint:// i used it to return to the beginning everytime when small programs finish
	cout << "Please type the number of program you want to check" << endl;
	cout << "1. Calculate the x in the power of y using recursion" << endl;
	cout << "2. Find sum of natural numbers using recursion 1 + 2 + 3 + 4...n" << endl;
	cout << "3. Fabonacci series" << endl;
	cout << "4. GCD of two numbers" << endl;
	cout << "Type 5 to exit the program" << endl;
	reenter:// this is for requiring a valid option for switch. No program continued unless valid number entered
	cin >> i;
	switch (i)
	{
	case 1:
	{
		int x, y;
		cout << "Please Input the number" << endl;
		cin >> x;
		cout << "Please input the power" << endl;//asks for input
	repow:// if power is negative number, it asks for positive input
		cin >> y;
		if (y < 0)
		{
			cout << "Please input not negative integer number for Power" << endl;
			goto repow;
		}
		cout << x << " in the power of " << y << " is equal to :" << pow(x, y) << endl << endl;// calls and prints the pow function
		goto startingpoint;
	}
	case 2:
	{
		int n;// n is int type
		cout << "Enter the number to find sum of serie" << endl;
		inputagain:
		cin >> n;
		if (n < 1)// requires for natural number input
		{
			cout << "Please enter a Natural number" << endl;
			goto inputagain;
		}
		cout<<"The sum of numbers before and "<<n<<" is equal to: "<<summ(n)<<endl;/// cals and prints summ function
		goto startingpoint;
	}
	case 3:
	{ 
		int m;
		cout << "Enter the number to find Feboacci Series" << endl;
		chooseagain:// for avoiding wrong input
		cin >> m;
		if (m < 1)
		{
			cout << "Please choose more than 1" << endl;
			goto chooseagain;
		}
		else
		{
			cout << "Fabonacci serie untill and with the number " << m << " is as follows: " << endl;
			for (int j=1; j<=m; j++)// here I used for loop to call function many times
			{
				cout <<febonacci(j) <<", ";// calling function
			}
			cout << endl;
		}
		goto startingpoint;
	}
	case 4:
	{
		int x, y;
		cout << "Input two numbers to find their GCD" << endl;
		cin >> x >> y;// here we input two numbers
		cout <<"The GCD of these numbers is equal to: " <<GCD(x, y) << endl;// we call the function

		goto startingpoint;
	}
	case 5:
	{
		goto exitdoor;// this is for exiting my program
	}
	default:// if any other number inputted, this will ask to input a valid option
	{
		cout << "Please choose a valid option" << endl;
		goto reenter;
	}
	}
exitdoor:// goto statement
	cout << " Thank you professor for checking my program" << endl;// this is for userfriendliness)
	cout << " See you next week" << endl;


	system("pause");
	return 0;
}