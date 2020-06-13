#ifndef __CITIZEN
#define __CITIZEN

#include "date.h"
#include <string>
#include <vector>
#include <fstream>


class Citizen
{
protected:
	string name;
	Date birthday;
	int id;
	int ballotNum;
	bool isIsolated;

public:

	Citizen(); //Default c'tor
	Citizen(const string name, const Date& birthday, int id, int ballotNum, bool isIsolated) throw (const char*, const char*); //C'tor
	Citizen(const Citizen& other); //Copy c'tor
	Citizen(ifstream& in); //File c'tor

	 //Get methods
	const string& getName() const; //Name is 'const' - can't change name
	const Date& getBirth() const; //Birthday is 'const' - can't change date of birth
	const int getId() const; //Id is 'const' - can't change id
	int getBallotNum() const;
	bool getIsIsolated() const;

	//Set methods
	bool setName(const string citizenName);
	bool setBirth(Date birth);
	bool setId(int id);
	bool setBallotNum(int bn);
	bool setIsIsolated(bool ans);

friend ostream& operator<<(ostream& out, const Citizen& citizen)
	{
		out << citizen.name << '\n' << citizen.birthday << "\n" << citizen.id << "\n"
			<< citizen.ballotNum << '\n' << citizen.isIsolated;
		return out;
	}

	friend istream& operator >> (istream& in, Citizen& citizen)
	{
		char delimiter;
		in >> delimiter >> citizen.name >> delimiter >> citizen.birthday >> delimiter
			>> citizen.id >> delimiter >> citizen.ballotNum >> delimiter >> citizen.isIsolated >> delimiter;
		return in;
	}

	virtual void show() const; //Show methods

};

#endif // !__CITIZEN