#include "iostream"

using namespace std;

int main(void)
{
	struct TIME {
		unsigned int h;
		unsigned int m;
	} time1;

	unsigned int hours, minutes;

	cout << "Enter hours: ";
	cin >> hours;

	cout << "Enter minutes: ";
	cin >> minutes;

	if (hours >= 24 ||  minutes >= 60) cout << "Bad input!";
	else
	{
		time1 = { hours , minutes };

		cout << "Enter minutes to end: ";
		cin >> minutes;

		hours = (minutes / 60) % 24;
		minutes %= 60;

		if (time1.m + minutes < 60) time1.m += minutes;
		else
		{
			hours++;

			time1.m += minutes-60;
		}

		time1.h = (time1.h + hours) % 24;

		cout << "Result " << time1.h << ":" << time1.m << endl;
	}

	system("pause");
	return 0;
}