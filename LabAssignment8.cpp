/* Name: Shukhratov Bekhzod
  Program: Lab Assignment 8, program 1, part 2*/

#include<iostream>
#include<string>//to avoid problems with string errors
using namespace std;
class Staff
{
private:
	string code, name;//these are only accessed in the class so they are private
public:
	Staff()//default constructor
	{
		//cout << "Constructor of SuperClass" << endl;
		code = "NoCodeGiven";
		name = "Unknown Name";
	}
	void setStaff()//to set the values
	{
		cout << "Input Staff Code" << endl;
		cin >> code;
		cout << "Input Staff Name" << endl;
		cin >> name;
	}
	void getStaff()
	{
		cout << "Staff Code: " << code << endl;
		cout << "Staff Name: " << name << endl;
	}
};//======================================================================
class Teacher :public Staff//Teacher class is inherited to Staff, parent class
{
private:
	string subject;
	int publication;
public:
	Teacher() {}
	Teacher(string su, int pu)//parametrized constructor
	{
		//cout << "Constructor of Teacher Class" << endl;
		subject = su;
		publication = pu;
	}
	void setTeacher()
	{
		cout << "Input Subject name" << endl;
		cin >> subject;
		cout << "Input Publication Number (Integer)" << endl;
		cin >> publication;
	}
	void getTeacher()
	{
		cout << "Subject Name: " << subject << endl;
		cout << "Publications: " << publication << endl;
	}
};//=====================================================================
class Officer :public Staff//Officer class is inherited from super class Staff publicly
{
private:
	string grade;
public:
	Officer() {}
	Officer(string gr)//parametrized constructor
	{
		//cout << "Constructor of Officer Class" << endl;
		grade = gr;
	}
	void setOfficer()
	{
		cout << "Input the Grade of Officer" << endl;
		cin >> grade;
	}
	void getOfficer()
	{
		cout << "The Grade of Officer: " << grade << endl;
	}
};//======================================================================
class Typist :public Staff//Staff is parent class for class Typist
{
private:
	float speed;
public:
	Typist()
	{
		//cout << "Constructor of Typist Class" << endl;
		speed = 0;
	}
	void setTypistSpeed()
	{
		cout << "Input number of words per minute" << endl;
		cin >> speed;
	}
	void getTypistSpeed()
	{
		cout << "The speed of typist: " << speed << endl;
	}
};//======================================================================
class Regular :public Typist//the same here
{
private:
	float MonthlySalary;
public:
	Regular(float ms)
	{
		//cout << "Constructor of Regular Class" << endl;
		MonthlySalary = ms;
	}
	void setRegular()
	{
		cout << "Input the Monthly Salary" << endl;
		cin >> MonthlySalary;
	}
	void getRegular()
	{
		cout << "Monthly Salary: " << MonthlySalary << endl;
	}
};//======================================================================
class Casual :public Typist
{
private:
	float DailyWages;
public:
	Casual(float ws)
	{
		//cout << "Constructor of Casual Class" << endl;
		DailyWages = ws;
	}
	void setCasual()
	{
		cout << "Set the Daily Wages" << endl;
		cin >> DailyWages;
	}
	void getCasual()
	{
		cout << "Daily Wages: " << DailyWages << endl;
	}
};//======================================================================
class Education :public Teacher, public Officer//multiple inheritance
{
private:
	string HighestProfessionalQualification;
public:
	Education() {}//default constructor
	Education(string hp)//parametrized constructor
	{
		HighestProfessionalQualification = hp;
	}
	void setEducation()
	{
		cout << "Set The Education" << endl;
		cin >> HighestProfessionalQualification;
	}
	void getEducation()
	{
		cout << "Highest Education: " << HighestProfessionalQualification << endl;
	}

};
int main()
{
	int j;
	while (true)// to not exit from the program when one part ends
	{
		cout << endl << "Which Staff Do You Choose?" << endl;// the rest is simple
		cout << "Type 1 for Teacher" << endl << "Type 2 for Officer" << endl;
		cout << "Type 3 for Typist" << endl << "Type 4 to see Highest Education" << endl;
		cout << "Type 5 to exit the program" << endl;
		cin >> j;
		switch (j)
		{
		case 1:
		{
			Teacher t("NoSubjectGiven", 0);// parametrized object
			t.setStaff();
			t.setTeacher();
			cout << endl;
			t.getStaff();
			t.getTeacher();
			break;
		}
		case 2:
		{
			Officer o("No Grade");
			o.setStaff();
			o.setOfficer();
			cout << endl;
			o.getStaff();
			o.getOfficer();
			break;
		}
		case 3:
		{
			string rc;
			while (true)// this will run untill user enters r or c
			{
				cout << "Regular or Casual Typist? (r/c)" << endl;
				cin >> rc;
				if (rc == "r")
				{
					Regular r(0);
					r.setStaff();
					r.setTypistSpeed();
					r.setRegular();
					cout << endl;
					r.getStaff();
					r.getTypistSpeed();
					r.getRegular();
					break;
				}
				else if (rc == "c")
				{
					Casual c(0);
					c.setStaff();
					c.setTypistSpeed();
					c.setCasual();
					cout << endl;
					c.getStaff();
					c.getTypistSpeed();
					c.getCasual();
					break;
				}
			}
			break;
		}
		case 4:
		{
			Education e("No Diploma yet");
			cout << "Which to choose Teacher or Officer? (t/o)" << endl;
			string g;
			while (true)
			{
				cin >> g;
				if (g == "t")
				{
					e.setTeacher();
					break;
				}
				else if (g == "o")
				{
					e.setOfficer();
					break;
				}
			}
			e.setEducation();
			if (g == "t")
			{
				e.getTeacher();
			}
			else
			{
				e.getOfficer();
			}
			e.getEducation();
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