#include "iostream"

using namespace std;

bool isLeap(int year)
{
	if (year % 4 != 0) return 0;			//the year number isn't divisible by 4, it is a common year;
	if (year % 100 != 0) return 1;		//otherwise, if the year number isn't divisible by 100, it is a leap year;
	if (year % 400 != 0) return 0;	//	otherwise, if the year number isn't divisible by 400, it is a common year;
	
	return 1;
}

int main(void)
{
	for (int yr = 1995; yr < 2017; yr++)
		cout << yr << " -> " << isLeap(yr) << endl;

	system("pause");
	return 0;
}