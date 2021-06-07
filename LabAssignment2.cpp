/*Name: Shukhratov Bekzhod
  Student ID: U2010259
  Program statement: Week13Assignment.
  1. To find pascal triangle
  2. Program to do operations with matricies
  3. Program to display numbers of products sold with matricies*/

#include<iostream>//header file
using namespace std;
int main()
{
	int i;// i is int type because choices are integers
startingpoint:// i used it to return to the beginning everytime when small programs finish
	cout << endl;
	cout << "Please type the number of program you want to check" << endl;
	cout << "1. Program to find Pascal Triangle " << endl;
	cout << "2. Program to do operations with matricies" << endl;
	cout << "3. Program to display numbers of products sold with matricies" << endl;
	cout << "Type 4 to exit the program" << endl;
reenter:// this is for requiring a valid option for switch. No program continued unless valid number entered
	cin >> i;
	switch (i)
	{
	case 1:
	{
		int rows, num = 1;

		cout << "Enter number of rows: ";
		cin >> rows;// here we input the rows

		for (int i = 0; i < rows; i++)// formula to find pascal triangle
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0 || i == 0)
					num = 1;
				else
					num=num* (i - j + 1) / j;

				cout << num << " ";
			}
			cout << endl;
		}

		goto startingpoint;// goes to the starting point
	}
	case 2:
	{
		int A[15][15], B[15][15];// maximum values of elements is 15
		int row, col;
		cout << "Enter Rows and Columns" << endl;
		cin >> row >> col;// here we input the rows and columns' number
		cout << "Enter Array elements" << endl;
		for (int i = 0; i<row; i++)// to input
		{
			for (int j = 0; j<col; j++)
			{
				cin >> A[i][j];
			}
		}
		cout << "The matrix will be: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout<< A[i][j]<<"\t";// to display the array
			}
			cout<< endl;
		}
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				B[i][j] = A[j][i];// here we transpose one matrix into another
			}
		}
		cout << "The Transpose of matrix will be: " << endl;// here it prints the result
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				cout << B[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "Enter number to multiply the Matrix elements" << endl;
		int k;// scalar number to multiply matricies
		cin >> k;
		cout << "The multiplied Matrix will be: " << endl;// prints the results
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout <<k* A[i][j] << "\t";
			}
			cout << endl;
		}

		goto startingpoint;
	}
	case 3:
	{
		cout << "Enter the Number of first product sold by 5 salesmen" << endl;
		int c[3][5];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cin >> c[i][j];// here we input the number of sold products
			}
			cout << "Now Another product's numbers" << endl;
		}
		cout << "The Matrix of sold products will be: " << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << c[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "The total sums of sold products: " << endl;
		cout << "The number of sold first products by 5 Salesman " << endl<<endl;
		for (int i = 0; i < 5; i++)
		{
			int v = 0;
			v = v + c[0][i];// here it adds all the products sold
			cout << v <<"  ";
		}
		cout << endl;
		cout << "The number of sold second products by 5 Salesman " <<endl<< endl;
		for (int i = 0; i < 5; i++)
		{
			int v = 0;
			v = v + c[1][i];
			cout << v << "  ";
		}
		cout << endl;
		cout << "The number of sold  third products by 5 Salesman, see the last number " << endl<<endl;
		for (int i = 0; i < 5; i++)
		{
			int v = 0;
			v = v + c[2][i];
			cout << v << "  ";
		}




		goto startingpoint;
	}
	case 4:
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
	cout << " Today is 31.12.2020, Happy New Year Teacher" << endl;// this is for userfriendliness)
	cout << " See you next week" << endl;


	system("pause");
	return 0;
}