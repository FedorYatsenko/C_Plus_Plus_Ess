#include "iostream"

using namespace std;

int main(void)
{
	int year;
	cout << "Enter a year: ";
	cin >> year;
	
	if (year % 4 != 0) cout << "Common year";			//the year number isn't divisible by 4, it is a common year;
	else if (year % 100 != 0) cout << "Leap year";		//otherwise, if the year number isn't divisible by 100, it is a leap year;
	else if (year % 400 != 0) cout << "Common year";	//	otherwise, if the year number isn't divisible by 400, it is a common year;
	else cout << "Leap year";							//otherwise, it is a leap year.
	
	cout << endl;
	system("pause");

	return 0;
}