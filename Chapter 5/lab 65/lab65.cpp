#include <iostream>
#include "string"

using namespace std;

class FlightBooking
{
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
private:
	int id;
	int capacity;
	int reserved;
};

void FlightBooking::printStatus()
{
	cout << "Flight " << id << ": " << reserved << '/' << capacity << " (" << (100 * reserved) / capacity << "%) sets taken" << endl;
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


int main()
{
	int reserved = 0,
		capacity = 0;

	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;

	FlightBooking booking(1, capacity, reserved);

	string command = "";
	int value;

	cin.get();

	while (command != "quit")
	{
		booking.printStatus();

		cout << "What would you like to do?: ";
		getline(cin, command);

		if (command.substr(0, 4) == "add ")
		{
			value = atoi(command.substr(4).c_str());

			if(!booking.reserveSeats(value))
				cout << "Cannot perform this operation" << endl;
		}
		else
			if (command.substr(0, 7) == "cancel ")
			{
				value = atoi(command.substr(7).c_str());

				if(!booking.cancelReservations(value))
					cout << "Cannot perform this operation" << endl;
			}
			else if (command != "quit") cout << "Cannot perform this operation" << endl;
	}

	system("pause");
	return 0;
}