#include "iostream"

using namespace std;

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

int main(void)
{
	for (int yr = 2000; yr < 2002; yr++)
	{
		for (int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr, mo) << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}