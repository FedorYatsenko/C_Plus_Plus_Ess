#include "iostream"

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

bool isLeap(int year)
{
	if (year % 4 != 0) return 0;			//the year number isn't divisible by 4, it is a common year;
	if (year % 100 != 0) return 1;		//otherwise, if the year number isn't divisible by 100, it is a leap year;
	if (year % 400 != 0) return 0;	//	otherwise, if the year number isn't divisible by 400, it is a common year;

	return 1;
}

int monthLength(int year, int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;

	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;

	if (month == 2) return (28 + isLeap(year));

	return 0;
}

int dayOfYear(Date date)
{
	int result = date.day;

	for (int i = 1; i < date.month; i++)
		result += monthLength( date.year, i);

	return result;
}

int main(void)
{
	Date d;

	cout << "Enter year month day: ";
	cin >> d.year >> d.month >> d.day;
	
	cout << dayOfYear(d) << endl;
	
	system("pause");
	return 0;
}