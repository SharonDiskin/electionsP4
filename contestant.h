#ifndef __CONTESTANT
#define __CONTESTANT

#include <fstream>
#include "citizen.h"

class Contestant : virtual public Citizen
{
private:
	string partyName;

public:
	Contestant(const string partyName, const string name, const Date& birthday, int id, int ballotNum, bool isIsolated); //C'tor
	Contestant(const Contestant& other); //Copy c'tor
	Contestant(ifstream& in); //File c'tor

	const string& getPartyName() const;
	bool setPartyName(string partyName);

	void show() const;

	friend ostream& operator<<(ostream& out, const Contestant& contestant)
	{
		out << contestant.partyName << '\n' << contestant.name << '\n' << contestant.birthday << "\n" << contestant.id << "\n"
			<< contestant.ballotNum << '\n' << contestant.isIsolated;
		return out;
	}

	friend istream& operator >> (istream& in, Contestant& contestant)
	{
		char delimiter;
		in >> delimiter >> contestant.partyName >> contestant.name >> delimiter >> contestant.birthday >> delimiter
			>> contestant.id >> delimiter >> contestant.ballotNum >> delimiter >> contestant.isIsolated >> delimiter;
		return in;
	}

};
#endif // !__CONTESTANT