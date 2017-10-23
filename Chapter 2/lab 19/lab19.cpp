#include <iostream>

using namespace std;

int main(void)
{
	int side;

	cout << "Enter a positive integer value greater than 1 (n)\n";
	cin >> side;

	if (side <= 1) cout << "Sorry, the side size is too small or negative" << endl;
	else if (side > 20) cout << "Sorry, the side size is too big" << endl;
	else
	{
		cout << '+';

		for (int i = 0; i < side; i++)
			cout << '-';

		cout << '+' << endl;
		
		for (int i = 0; i < side; i++)
		{
			cout << '|';
			
			for (int j = 0; j < side; j++)
				cout << ' ';

			cout << '|' << endl;
		}

		cout << '+';
		
		for (int i = 0; i < side; i++)
			cout << '-';
		
		cout << '+' << endl;
	}

	system("pause");
	return 0;
}