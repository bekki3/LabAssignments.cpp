#include<iostream>
#include<fstream>//to work with files
using namespace std;
class Person
{
public:
	string name, telephonenum;
public:
	Person(){}//empty default constructor
	void setdata()//parametrized setdata
	{
		cout << "enter name" << endl;
		cin >> name;
		cout << "Enter telnum" << endl;
		cin >> telephonenum;
	}
	void getdata()
	{
		cout << "Name: " << name<<"    ";
		cout << "Telephone Number: " << telephonenum;
	}
};
int main()
{
	string name, telephonenum, temp="y";// string variables
	ofstream obj1("Somefile.txt", ios::app, ios::binary);// openigna binary file in append mode
	Person p;// objext p is class Person
	while (true)
	{

		while (temp == "y" || temp == "Y")// to add contacts
		{
			/*cout << "Enter Name and Telephone Number" << endl;
			cin >> name >> telephonenum;*/
			//p.setdata();// assigning variable
			//obj1.write((char*)&p, sizeof(Person));//to write address of obj to the file
			cout << "If you want to add contact, type y" << endl << "Or tap any key to skip." << endl;
			cin >> temp;
		}
		int k;
		cout << "Which Menu you want to choose? (1-5)" << endl;
		cout << "Type 1 to Find Number by Name" << endl;
		cout << "Type 2 to Find Name by Number" << endl;
		cout << "Type 3 to Delete a Record in the file" << endl;
		cout << "Type 4 to Add data to the file" << endl;
		cout << "Type 5 to Exit the program" << endl;
		cin >> k;
		switch (k)//////////////////////////////////////////////////////////
		{
		case 1:
		{
			ifstream obj2;
			obj2.open("Somefile.txt", ios::binary);
			string tempstr, tempdata="Data Not Found";
			cout << "Enter the Name: ";
			cin >> tempstr;
			while (obj2.read((char*)&p, sizeof(Person)))// setting the values of file to the class variable
			{
				if (p.name == tempstr)// if the item is found
				{
					tempdata = "Data Found!";
					cout << "The Phone Number: " << p.telephonenum << endl;
					obj2.close();
				}
			}
			cout << tempdata << endl;
			break;
		}
		case 2:
		{
			ifstream obj3;
			obj3.open("Somefile.txt", ios::binary);
			string tempstr1, tempdata = "Data Not Found";
			cout << "Enter the Number: ";
			cin >> tempstr1;
			while (obj3.read((char*)&p, sizeof(Person)))
			{
				if (p.telephonenum == tempstr1)
				{
					tempdata="Data Found!";
					cout << "The Name: " << p.name << endl;
					obj3.close();
				}
			}
			cout << tempdata << endl;
			break;
		}
		case 3:
		{
			cout << "Enter the Number of record you want to delete" << endl;
			int t;
			cin >> t;
			ofstream fout;
			fout.open("temp.txt", ios::binary, ios::app);// creating a new temp file to copy the needed items
			ifstream fin;
			fin.open("Somefile.txt", ios::binary);
			fout.seekp(0, ios::end);
			while (fin.read((char*)&p, sizeof(p)))// while not the end of file
			{
				for (int i = 0; i != t; i = i + fout.cur / sizeof(p))// steps by records
				{
					fout.write((char*)&p, sizeof(p));// it will copy records other than chosen one
				}
			}
			fin.close();
			fout.close();
			remove("Somefile.txt");//it wll delete the old file
			rename("temp.txt", "Somefile.txt");// renaming the new file
			break;
		}
		case 4:
		{
			obj1.seekp(0, ios::end);
			int num;
			int n = obj1.tellp() / sizeof(p);// bytes in the file//num of records
			cout << "Enter Record Number in which you want to add" << endl;
			cin >> num;
			int pos = (num - 1) * sizeof(p);// this is to find the needed record postition
			//cout << "Pos: " << pos << endl;
			obj1.seekp(pos);//seeking the position
			cout << "Enter Name and Telephone Number to add" << endl;
			cin >> name >> telephonenum;
			p.setdata();// assigning variable
			obj1.write((char*)&p, sizeof(Person));//to write address of obj to the file
			obj1.close();
			break;
		}
		case 5: 
		{
			exit(0);
		}
		}
	}
	system("pause");
	return 0;
}