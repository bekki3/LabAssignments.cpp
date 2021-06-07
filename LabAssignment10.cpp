/* Name: Shukhratov Bekhzod U2010259
Program Statement: Lab Assignment 10, Program 2*/
#include<iostream>
#include<string>
#include<fstream>//to work with files
using namespace std;
int main()
{
	string names[20];// string array
	names[0] = "Abbos      ";
	names[1] = "Nosir      ";
	names[2] = "Abdullo    ";
	names[3] = "Akbar      ";
	names[4] = "Akmal      ";
	names[5] = "Alisher    ";
	names[6] = "Asad       ";
	names[7] = "Asl        ";
	names[8] = "Azamat     ";
	names[9] = "Aziz       ";
	names[10] = "Bobur      ";
	names[11] = "Botir      ";
	names[12] = "Donka      ";
	names[13] = "Elchin     ";
	names[14] = "Farrux     ";
	names[15] = "Fotih      ";
	names[16] = "Hasan      ";
	names[17] = "Hurshid    ";
	names[18] = "Husan      ";
	names[19] = "Jalol      ";
	int numbers[20];////////////// for keeping numbers in one array
	numbers[0] = 1779;
	numbers[1] = 3666;
	numbers[2] = 1323;
	numbers[3] = 1114;
	numbers[4] = 2464;
	numbers[5] = 8810;
	numbers[6] = 3454;
	numbers[7] = 5444;
	numbers[8] = 8496;
	numbers[9] = 8434;
	numbers[10] = 9430;
	numbers[11] = 3423;
	numbers[12] = 6734;
	numbers[13] = 3657;
	numbers[14] = 3453;
	numbers[15] = 1223;
	numbers[16] = 4332;
	numbers[17] = 1211;
	numbers[18] = 2723;
	numbers[19] = 7907;
	ofstream obj1;// to write in a file
	obj1.open("Numbers.txt");// opening a file
	for (int i = 0; i < 20; i++)// to write in the file
	{
		obj1 << names[i] << endl;
		obj1 << numbers[i] << endl;
	}
	obj1.close();// closing file after writing
	ifstream obj2("Numbers.txt");// opening the text file to read from it
	string temp;
	int i=0;
	while(i<40)// this will show 20 contacts
	{
		obj2 >> temp;// assigning values of the obj to tem variable
		cout << temp;
		if (i % 2 == 1)//to separate contacts by endl
		{
			cout << endl;
		}
		else if(i % 2 == 0)
		{
			cout << "\t";// for indentation among contacts
		}
		i++;
	}
	obj2.close();
	ifstream obj3("Numbers.txt");//opening the text file to read from it
	cout << "Enter which Phone Number you want to search" << endl;
	int tempint;
	cin >> tempint;
	for(int i=0; i<40; i++)// for checking all the contacts
	{
		obj3 >> temp;// getting values from file and assigning to temp
		if (i%2==1)// to get only integers without stirngs
		{
			//cout << stoi(temp) << endl;
			if (stoi(temp) == tempint)// if contact is found
			{
				cout << "Contact is Found" << endl;
				exit(0);
			}
		}
	}
	obj3.close();
	cout << "Contact is NOT Found" << endl;
	system("pause");
	return 0;
}