#include <iostream>

using namespace std;

int main(void)
{
	bool answer;
	int value;
	cout << "Enter a value: ";
	cin >> value;

	answer = (value >= 0 && value < 10) ||		// is greater than or equal to 0 and less than 10, or
		(value * 2 < 20 && value - 2 > 2) ||	// multiplied by 2 is less than 20 and reduced by 2 is greater than minus 2, or
		(value - 1 > 1 && value / 2 < 10) ||	//reduced by 1 is greater than 1 and divided by 2 is less than 10, or
		(value == 111);							// is equal to 111.

	cout << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;

	system("pause");
	return 0;
}