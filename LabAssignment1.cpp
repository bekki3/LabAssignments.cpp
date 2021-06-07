/*Name: Shukhratov Bekzhod
  Student ID: U2010259
  Program statement: Week12Assignment.
  1. Write a program to display an Array
  2. A program to find average of array elements
  3. Program to merge to sorted arrays
  4. Program to insert an element to an array
  5. Program to delete an element from an array    */

#include<iostream>//header file
using namespace std;
int main()
{
	int i;// i is int type because choices are integers
startingpoint:// i used it to return to the beginning everytime when small programs finish
	cout << endl;
	cout << "Please type the number of program you want to check" << endl;
	cout << "1. A program to display an Array "<< endl;
	cout << "2. A program to find average of array elements" << endl;
	cout << "3. Program to merge to sorted arrays" << endl;
	cout << "4. Program to insert an element to an array" << endl;
	cout << "5. Program to delete an element from an array" << endl;
	cout << "Type 6 to exit the program" << endl;
reenter:// this is for requiring a valid option for switch. No program continued unless valid number entered
	cin >> i;
	switch (i)
	{
	case 1:
	{
		int size, a[100];// size and array are type integer and maximum size for array is 100
		cout << "Enter the size of the array" << endl;// asks for input
		cin >> size;// here we assign the size of the array
		cout << "Enter the elements of the array" << endl;
		for (int i = 0; i < size; i++)// it will input elements starting from a[0]to a[size]
		{
			cin >> a[i];// we input the value
		}
		cout << "The elements of the array are as follows: " << endl;
		for (int i = 0; i < size; i++)// prints the elements starting from a[0]to a[size]
		{
			cout <<"a["<<i<<"]= "<< a[i] << endl;
		}

		goto startingpoint;// goes to the starting point
	}
	case 2:
	{

		int size, a[100];
		float sum = 0;// Sum is type float because when we divide two integers it may be decimal number.
		cout << "Enter the size of the array" << endl;
		cin >> size;
		cout << "Enter the elements of the array" << endl;
		for (int i = 0; i < size; i++)//it will input elements starting from a[0]to a[size]
		{
			cin >> a[i];
		}
		cout << "The elements of the array are as follows: " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "a[" << i << "]= " << a[i] << endl;
			sum = a[i] + sum;// this is to find the sum of elements
		}
		cout << "The average of the elements is equal to: " << sum / size<<" or " <<sum<<"/"<<size<< endl;// we find the average by dividing sum into number of elements

		
		goto startingpoint;
	}
	case 3:
	{
		
		int a1[15], a2[15], a3[30];// array 1 and 2 have maximum size of 15 elements
		int i, n1, n2, m, index = 0;
		int index1 = 0, index2 = 0;// thse are type integer because number of elements cannot be decimal
		cout << "Enter the number of elements in array 1" << endl;
		cin >> n1;
		cout << "Enter elements of first array" << endl;
		for (i = 0; i < n1; i++)
		{
			cin >> a1[i];
		}
		cout << "The elements of the first array: " << endl;// these are usual processes we know already
		for (i = 0; i < n1; i++)
		{
			cout << a1[i] << endl;
		}
		cout << "Enter the number of elements in array 2" << endl;
		cin >> n2;
		cout << "Enter the elemts of the array" << endl;
		for (int i = 0; i < n2; i++)
		{
			cin >> a2[i];
		}
		cout << "The elements of the second array: " << endl;
		for (int i = 0; i < n2; i++)
		{
			cout << a2[i] << endl;
		}
		m = n1 + n2;//m is the final number of elements of sorted array
		while (index1 < n1 && index2 < n2)
		{
			if (a1[index1] < a2[index2])// less array's element will be chosen to input for a3
			{
				a3[index] = a1[index1];
				index1++;
			}
			else
			{
				a3[index] = a2[index2];//if a2 is less than a1 then it will be assigned for a3
				index2++;
			}
			index++;/// to move to the next elelment
		}
		if (index1 = n1)// this will be performed when while loop goes to the end of a1 array
		{
			a3[index] = a2[index2];
			index2++;
			index++;
		}
		else if (index2 = n2)
		{
			a3[index] = a1[index1];
			index1++;
			index++;
		}
		cout << "The merged array is: " << endl;
		for (i = 0; i < m; i++)// simply displays the elements
		{
			cout << a3[i] << endl;
		}



		goto startingpoint;
	}
	case 4:
	{
		
		int a[50];
		int n, pos, num;
		cout << "Input the number of elements in the array" << endl;
		cin >> n;
		cout << "Input array elements" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << "Array elements are: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << endl;
		}
		cout << "Input the value which you want to insert" << endl;
		cin >> num;
		cout << "Input the position at which you want to insert: " << endl;
		cin >> pos;
		for (int i = n; i >= pos; --i)
		{
			a[i + 1] = a[i];// the element of one place will be moved to place+1
		}
		a[pos] = num;
		cout << "After insertion, array elements are as follows: " << endl;
		for (int i = 0; i < n + 1; i++)
		{
			cout << a[i] << endl;
		}

		goto startingpoint;
	}
	case 5:
	{

		int a[50];
		int n, pos;
		cout << "Input the number of elements in the array" << endl;
		cin >> n;
		cout << "Input array elements" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << "Array elements are: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << endl;
		}
		cout << "Input the position which you want to delete: " << endl;
		cin >> pos;
		for (int i = pos; i < n; i++)
		{
			a[i] = a[i+1];// one place in array will be replaced with place+1 and will repeat with following elements untill the difference of pos and size
		}
		n--;
		cout << "After deletion, array elements are as follows: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << endl;
		}



		goto startingpoint;
	}
	case 6:
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