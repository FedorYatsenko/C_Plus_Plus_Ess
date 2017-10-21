#include "iostream"

using namespace std;

int main(void)
{
	int year, month, day, result;

	cout << "Input year: ";
	cin >> year;

	cout << "Input month: ";
	cin >> month;

	cout << "Input day: ";
	cin >> day;

	if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31)
		cout << "Wrong date";
	else
	{
		month -= 2;				//	1. Decrease month number by 2;

		if (month <= 0)			//	2. if month number becomes less than 0, increment it by 12 and decrement year by 1;
		{
			month += 12;
			year--;
		}

		month *= 83;			//	3. take month number and multiply it by 83 and divide it by 32;
		month /= 32;

		month += day;			//	4. add day number to month;
		month += year;			//	5. add year number to month;
		month += year / 4;		//	6. add year / 4 to month;
		month -= year / 100;	//	7. subtract year / 100 from month;
		month += year / 400;	//	8. add year / 400 to month;
		result = month % 7;		//	9. find the remainder of dividing month by 7;
	
		cout << "A weekday number is " << result << endl;	//	10. Congrats!A weekday number is ready for you!0 – Sunday, 1 – Monday, ... and so on.*/
	}
		

	system("pause");
	return 0;
}