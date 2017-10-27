#include "iostream"

using namespace std;

int main(void)
{
	struct TIME {
		unsigned int h;
		unsigned int m;
	} time1, time2;

	unsigned int hours1, minutes1,
		hours2, minutes2;

	cout << "Enter hours: ";
	cin >> hours1;

	cout << "Enter minutes: ";
	cin >> minutes1;

	cout << "Enter hours: ";
	cin >> hours2;

	cout << "Enter minutes: ";
	cin >> minutes2;

	if (hours1 >= 24 || minutes1 >= 60 || hours2 >= 24 || minutes2 >= 60 || hours1 > hours2 || (hours1 == hours2 && minutes1 > minutes2) ) cout << "Bad input!";
	else
	{
		time1 = { hours1, minutes1 };
		time2 = { hours2, minutes2 };

		if (time1.m > time2.m)
		{
			time2.h--;
			time2.m += 60;
		}

		time2.h -= time1.h;
		time2.m -= time1.m;

		cout << "Result " << time2.h << ":" << time2.m << endl;
	}

	system("pause");
	return 0;
}