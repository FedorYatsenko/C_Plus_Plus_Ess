#include <iostream>

using namespace std;

int main(void)
{
	int height;

	cout << "Enter pyramid's height: ";
	cin >> height;

	for (int i = 0; i < 11; i++)
		cout << " ";
	cout << "*";

	for (int i = 0; i < 15; i++)
		cout << " ";
	cout << "*";

	for (int i = 0; i < 15; i++)
		cout << " ";
	cout << "*" << endl;

	int j;

	for (int i = 1; i < height - 1; i++)
	{
		for (j = 0; j < 11 - i; j++)
			cout << " ";
		cout << "*";

		for (j++; j < 11 + i; j++)
			cout << " ";
		cout << "*";

		for (; j < 26 - i; j++)
			cout << " ";
		cout << "*";

		for (j++; j < 26 + i; j++)
			cout << " ";
		cout << "*";

		for (; j < 41 - i; j++)
			cout << " ";
		cout << "*";

		for (j++; j < 41 + i; j++)
			cout << " ";
		cout << "*" << endl;
	}

	for (j = 0; j < 11 - (height - 1); j++)
		cout << " ";

	for (; j < 11 + height; j++)
		cout << "*";

	for (; j < 26 - (height - 2); j++)
		cout << " ";

	for (; j < 26 + height + 1; j++)
		cout << "*";

	for (; j < 41 - (height - 3); j++)
		cout << " ";

	for (; j < 41 + height + 2; j++)
		cout << "*";

	cout << endl;
	system("pause");
	return 0;
}