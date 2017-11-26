#include <iostream>
#include <string>

using namespace std;

const int Length = 10;

class FlightBooking
{
public:
	FlightBooking(int id, int capacity, int reserved);
	FlightBooking();
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
	int getId() { return id; }
private:
	int id;
	int capacity;
	int reserved;
};
FlightBooking::FlightBooking()
{
	id = 0; capacity = 0; reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;

	if (reserved < 0) reserved = 0;
	else
		if ((double)reserved / capacity > 1.05) reserved = (int)(capacity * 1.05);

	this->reserved = reserved;
}

bool FlightBooking::reserveSeats(int number_ob_seats)
{
	if (((double)reserved + number_ob_seats) / capacity > 1.05)
		return false;

	reserved = reserved + number_ob_seats;
	return true;
}

bool FlightBooking::cancelReservations(int number_ob_seats)
{
	if (reserved - number_ob_seats < 0)
		return false;

	reserved = reserved - number_ob_seats;
	return true;
}

void FlightBooking::printStatus()
{
	if (id == 0) cout << "Empty flight" << endl;
	else cout << "Flight " << id << ": " << reserved << '/' << capacity << " (" << (100 * reserved) / capacity << "%) sets taken" << endl;
}

int getIndex(int command, FlightBooking *booking, int id)
{
	if (command == 3)
	{
		for (int i = 0; i < Length; i++)
			if (booking[i].getId() == 0) return i;
	}
	else
	{
		for (int i = 0; i < Length; i++)
			if (booking[i].getId() == id) return i;
	}

	return -1;
}


bool ExecuteTheCommand(string command, FlightBooking *booking)
{
	int comm = 0,
		commEnd = 0;

	if (command == "quit") return true;

	if (command.substr(0, 4) == "add ")
	{
		comm = 1;
		commEnd = 4;
	}
	else
		if (command.substr(0, 7) == "cancel ")
		{
			comm = 2;
			commEnd = 7;
		}
		else
			if (command.substr(0, 7) == "create ")
			{
				comm = 3;
				commEnd = 7;
			}
			else
				if (command.substr(0, 7) == "delete ")
				{
					comm = 4;
					commEnd = 7;
				}

	if (comm == 0) return false;


	string idString = "",
		valueString = "";

	int id = -1,
		value = -1;

	for (; commEnd < command.length() && command[commEnd] != ' '; commEnd++)
		idString += command[commEnd];
	id = atoi(idString.c_str());

	if (id == -1) return false;

	for (commEnd++; commEnd < command.length(); commEnd++)
		valueString += command[commEnd];
	value = atoi(valueString.c_str());

	int index = getIndex(comm, booking, id);

	if (index == -1) return false;

	switch (comm)
	{
	case 1: // add
		return booking[index].reserveSeats(value);
		break;
	case 2: // cancel
		return booking[index].cancelReservations(value);
		break;
	case 3: // create
		booking[index] = FlightBooking(id, value, 0);
			return true;
			break;
	case 4: // delete
		booking[index] = FlightBooking();
		return true;
		break;
	default:
		break;
	}

	return false;
}

int main() {
	FlightBooking booking[Length];
	// Use this to have some starting value
	booking[0] = FlightBooking(1, 400, 0);
	booking[1] = FlightBooking(7, 200, 150);

	for (int i = 2; i < Length; i++)
	{
		booking[i] = FlightBooking();
	}

	string command = "";

	while (command != "quit")
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		for(int i = 0; i < Length; i++)
			booking[i].printStatus();

		cout << "What would you like to do?: ";

		getline(cin, command);

		// handle the command
		if (!ExecuteTheCommand(command, booking)) cout << "Cannot perform this operation" << endl;
	}
	return 0;
}