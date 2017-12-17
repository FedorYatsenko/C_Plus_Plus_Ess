#include <iostream>
#include <string>

using namespace std;

const int Length = 10;

class Member
{
public:
	Member();
	Member(int ID, string Name);
	void printStatus();
	bool extend(int monthsCount);
	bool cancel();
	int getId() { return id; }
private:
	int id;
	string name;
	int months;
};

Member::Member()
{
	id = 0; name = ""; months = 0;
}

Member::Member(int ID, string Name)
{
	if (ID > 0) id = ID;
	else id = 0;

	name = Name;
	months = 0;
}

bool Member::extend(int monthsCount)
{
	if (id == 0 || monthsCount <= 0) return false;

	months += monthsCount;
	return true;
}

bool Member::cancel()
{
	if (id == 0) return false;

	months = 0;
	return true;
}

void Member::printStatus()
{
	if (id == 0) cout << "Empty member" << endl;
	else cout << "Member " << id << ": " << name << ", subscription valid for " << months << " months" << endl;
}

int GetIndex(Member *mambers, int id)
{
	for (int i = 0; i < Length; i++)
		if (mambers[i].getId() == id) return i;

	return -1;
}

int GetEmptyIndex(Member *mambers)
{
	for (int i = 0; i < Length; i++)
		if (mambers[i].getId() == 0) return i;

	return -1;
}

bool Create(string data, Member *members)
{
	int index = 0;
	string id = "",
		name = "";

	for (; index < data.length() && data[index] != ' '; index++)
		id += data[index];

	for (index++; index < data.length(); index++)
		name += data[index];

	index = GetEmptyIndex(members);

	if (index == -1) return false;

	members[index] = Member(atoi(id.c_str()), name);

	return true;
}

bool Delete(string data, Member *members)
{
	int index = 0;
	string id = "";

	for (; index < data.length(); index++)
		id += data[index];

	index = GetIndex(members, atoi(id.c_str()));

	if (index == -1) return false;

	members[index] = Member();

	return true;
}

bool Extend(string data, Member *members)
{
	int index = 0;
	string id = "",
		months = "";

	for (; index < data.length() && data[index] != ' '; index++)
		id += data[index];

	for (index++; index < data.length(); index++)
		months += data[index];

	index = GetIndex(members, atoi(id.c_str()));

	if (index == -1) return false;

	members[index].extend(atoi(months.c_str()));

	return true;
}

bool Cancel(string data, Member *members)
{
	int index = 0;
	string id = "";

	for (; index < data.length(); index++)
		id += data[index];

	index = GetIndex(members, atoi(id.c_str()));

	if (index == -1) return false;

	members[index].cancel();

	return true;
}

bool ExecuteTheCommand(string command, Member *members)
{
	if (command == "quit") return true;

	if (command.substr(0, 7) == "create ") return Create(command.substr(7), members);

	if (command.substr(0, 7) == "delete ") return Delete(command.substr(7), members);

	if (command.substr(0, 7) == "extend ") return Extend(command.substr(7), members);

	if (command.substr(0, 7) == "cancel ") return Cancel(command.substr(7), members);

	return false;
}

int main() {
	Member members[Length];

	members[0] = Member(1, "Melman");
	members[1] = Member(3, "Alex");

	for (int i = 2; i < Length; i++)
	{
		members[i] = Member();
	}

	string command = "";

	while (command != "quit")
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		for (int i = 0; i < Length; i++)
			members[i].printStatus();

		cout << "What would you like to do?: ";

		getline(cin, command);

		// handle the command
		if (!ExecuteTheCommand(command, members)) cout << "Cannot perform this operation" << endl;
	}
	return 0;
}