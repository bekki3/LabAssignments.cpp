/*Name: Bekhzod Shukhratov U2010259
Program Statement: Lab Assignment 7 */
#include<iostream>
using namespace std;
class Publication// parent class
{
private:
	string title;
	double price;
public:
	Publication()//default not parametrized constructor
	{
		title = "Not Given";
		price = 0;
	}
	void setdata_Publication()// to set data
	{
		cout << "Please set the Title" << endl;
		cin >> title;
		cout << "Please set the Price" << endl;
		cin >> price;
	}
	void getdata_Publication()// to print data
	{
		cout << "The Title: " << title << endl;
		cout << "The Price: " << price << endl;
	}

};
class Book: public Publication// class Book is child of class publication publicly
{
private:
	int page_count;
public:
	void setdata_Book()// to set data
	{
		setdata_Publication();
		cout << "Please set the Page Count" << endl;
		cin >> page_count;
	}
	void getdata_Book()
	{
		getdata_Publication();
		cout << "Page Count: " << page_count << endl;
	}
};
class Tape: public Publication// this is child of class Publication. Has not connection with class Book
{
private:
	int playing_time;
public:
	void setdata_Tape()
	{
		setdata_Publication();
		cout << "Please set the Playing Time" << endl;
		cin >> playing_time;
	}
	void getdata_Tape()
	{
		getdata_Publication();
		cout << "Playing Time: " << playing_time << endl;
	}
};
///////////////////////////////////////////////////////////////////////
class Account// base class
{
protected:// only accessible between classes. no acces in the main func
	string customer_name, account_num;
	char account_type;
public:
	void setdata()
	{
		cout << "Enter Customer Name" << endl;
		cin >> customer_name;
		cout << "ENter Account Number" << endl;
		cin >> account_num;
	}
	void getdata()
	{
		cout << "Customer Name: " << customer_name << endl;
		cout << "Account Number: " << account_num << endl;
	}
};
class Curr_Account:public Account// derived class from Account class
{
private:// only accesible in this class
	double amount, penalty;
public:
	void Deposit()
	{
		cout << "How much you want to add to your money?" << endl;
		double n;
		cin >> n;
		amount =n;
		cout << "Deposite made!" << endl;
	}
	void Balance()
	{
		cout << "Your Balance is: " << amount << endl;
	}
	void Withdraw()
	{
		cout << "How much money you want to withdraw?" << endl;
		double k;
		cin >> k;
		if (k > amount)
		{
			cout << "Withdraw Impossible" << endl;
			cout << "You can only withdraw less than " << amount << endl;
		}
		else
		{
			amount -= k;
			cout << "Withdraw Made!" << endl;
		}
	}
	void Penalty()
	{
		if (amount < 100)
		{
			cout << "Penalty fro less than 100 dollar taken as 2 dollars" << endl;
			amount -= 2;
		}
		else
		{
			cout << "No Penalty is applies to your money" << endl;
		}
	}
};
class Sav_Account:public Account// child class of Account class//
{
private:
	double amount;
public:
	void Deposit()
	{
		cout << "How much you want to add to your money?" << endl;
		double n;
		cin >> n;
		amount = n;
		cout << "Deposite made!" << endl;
	}
	void Balance()
	{
		cout << "Your Balance is: " << amount << endl;
	}
	void Withdraw()
	{
		cout << "How much money you want to withdraw?" << endl;
		double k;
		cin >> k;
		if (k > amount)
		{
			cout << "Withdraw Impossible" << endl;
			cout << "You can only withdraw less than " << amount << endl;
		}
		else
		{
			amount -= k;
			cout << "Withdraw Made!" << endl;
		}
	}
	void Compute_Interest()// I  used a loop to derive the interest 
	{
		cout << "In how many years ypu will get your money back?" << endl;
		int y;
		cin >> y;
		for (int i = 0; i <= y; i++)
		{
			amount += (amount * 4);
		}
		cout << "The final Amount: " << amount << endl;
	}
};
int main()
{
	while (true)// to not exit immediately
	{
		cout << "Type the number of program you want to check! (1 or 2)" << endl;
		cout << "Type 0 to exit the program!" << endl;
		int j;
		cin >> j;
		if (j == 0)
		{
			exit(0);
		}
		switch (j)
		{
		case 1:
		{
			cout << "If you want to see details of a book, type 1" << endl;
			cout << "If you want to see details of a tape, type 2" << endl;
			int i;
			cin >> i;
			switch (i)
			{
			case 1:
			{
				Book somebook;//assigning and calling. The rest is simple old style
				somebook.setdata_Book();// I called functions of main class by assigning an object to a child class
				somebook.getdata_Book();
				break;
			}
			case 2:
			{
				Tape sometape;
				sometape.setdata_Tape();
				sometape.getdata_Tape();
				break;
			}
			}
			break;
		}
		case 2:
		{
			cout << "Which Type OF Account Do You Choose? (ca/ sa)" << endl;
			string type;
			cin >> type;
			if (type == "ca")
			{
				here:
				Curr_Account j;
				cout << "If you want to Set Details of the customer, type 1" << endl;
				cout << "If you want to Deposit, type 2" << endl;
				cout << "If you want to check Balance, type 3" << endl;
				cout << "If you want to Withdraw money, type 4" << endl;
				int f;
				cin >> f;
				switch (f)
				{
				case 1:
				{
					j.setdata();
					j.getdata();
					break;
				}
				case 2:
				{
					j.Deposit();
					break;
				}
				case 3:
				{
					j.Balance();
					break;
				}
				case 4:
				{
					j.Withdraw();
					j.Penalty();
					break;
				}
				}
				goto here;
			}
			else
			{
				while (true)
				{
					Sav_Account obj;
					cout << "If you want to Set Details of the customer, type 1" << endl;
					cout << "If you want to Deposit, type 2" << endl;
					cout << "If you want to check Balance, type 3" << endl;
					cout << "If you want to Compute Interest, type 4" << endl;
					cout << "If you want to Withdraw money, type 5" << endl;
					cout << "Otherwise, program will exit automatically" << endl;
					int d;
					cin >> d;
					if (d == 1)
					{
						obj.setdata();
						obj.getdata();
					}
					else if (d == 2)
						obj.Deposit();
					else if (d == 3)
					{
						obj.Balance();
					}
					else if (d == 4)
					{
						obj.Compute_Interest();
					}
					else if (d == 5)
						obj.Withdraw();
					else
						exit(0);
				}
			}
		}
		}
	}
	
	system("pause");
	return 0;
}