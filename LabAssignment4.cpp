/*Name: Shukhratov Bekhzod U2010259
Program Statement: Lab Assignment 4 */
#include<iostream>
using namespace std;
class FullName
{
private:
	string FirstName, MiddleName, LastName; //private variables of type string
public:
	FullName()// constructor
	{
		FirstName = "NoFirstName";
		MiddleName = "NoMiddleName";
		LastName = "NoLastName";
	}
	~FullName()
	{
		cout << "Target Terminated" << endl;
	}//destructor
	void setFirstName(string a)// set functions to set data
	{
		FirstName = a;
	}
	void setMiddleName(string b)
	{
		MiddleName = b;
	}
	void setLastName(string c)
	{
		LastName = c;
	}
	string getFirstName()// get functions return and display data
	{
		return FirstName;
	}
	string getMiddleName()
	{
		return MiddleName;
	}
	string getLastName()
	{
		return LastName;
	}
};
class Player// class of type player
{
	friend class Static;// we are saying that static function is friend of this class
private:
	string PlayerID;
	FullName PlayerName;
	int MatchesPlayed;
	int GoalsScored;
public:
	Player()// initializing the values of variables. Constructing
	{
		PlayerID = "NoID";
		MatchesPlayed = 0;
		GoalsScored = 0;
	}
	void SetPlayerID(string I)// functions to set data
	{
		PlayerID = I;
	}
	void setMatchesPlayed(int p)
	{
		MatchesPlayed = p;
	}
	void setGoalsScored(int g)
	{
		GoalsScored = g;
	}
	void setPlayerName(FullName N)
	{
		PlayerName = N;
	}
	string getPlayerID()// functions to get data. simple
	{
		return PlayerID;
	}
	int getMatchesPLayed()
	{
		return MatchesPlayed;
	}
	int getGoalsScored()
	{
		return GoalsScored;
	}
};
class Static
{
public:
	Player l;
	static int GoalsScored;//static getscore is type integer
	void setdata()
	{
		GoalsScored++;//incrementing
	}
	void getdata()
	{
		cout << "Goals Scored: " << GoalsScored << endl;
	}
};
int Static::GoalsScored;
int main()
{
	FullName a1, N;
	Player h;
	string a, b, c, I;
	int j, p, g;
	while (true)//////
	{
		cout << "Type 1, to set data. Type 2 to display the data" << endl;
		cout << "Type 3, to add goals number. Type 4 to delete the data" << endl;
		cin >> j;
		switch (j)
		{
		case 1:
		{
			string str1, str2, str3;
			cout << "Enter First Name: " << endl;
			cin >> str1;
			string* a = new string(str1);
			a1.setFirstName(*a);// allocating memory
			cout << "Enter Middle Name: " << endl;
			cin >> str2;
			string* b = new string(str2);///assigning a memory to a variable
			a1.setMiddleName(*b);
			cout << "Enter Last Name: " << endl;
			cin >> str3;
			string* c = new string(str3);
			a1.setLastName(*c);

			cout << "Set ID number "<< endl;
			cin >> I;
			cout << "Set number of matches Played" << endl;
			cin >> p;
			cout << "Set Number of Goals: " << endl;
			cin>> g;
			h.SetPlayerID(I);// here we only set data
			h.setMatchesPlayed(p);
			h.setGoalsScored(g);
			h.setPlayerName(N);
			//to set the data
		}
		case 2:
		{
			cout << "First Name: " << a1.getFirstName() << endl;// here we gte all the given data
			cout << "Middle Name: " << a1.getMiddleName() << endl;
			cout << "Last Name: " << a1.getLastName() << endl;
			cout << "PLayerID: " << h.getPlayerID() << endl;
			cout << "Matches Played: " << h.getMatchesPLayed() << endl;
			cout << "Goals Scored: " << h.getGoalsScored() << endl;
			break;
			//print the data
		}
		case 3:
		{
			Static f;// f is type class static
			f.setdata();
			f.getdata();
			//goal ++
			break;
		}
		case 4: 
		{
			delete& a, & b, & c;// deletes Player data
			//delete the data
		}
		}
	}


}