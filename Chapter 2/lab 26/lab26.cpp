#include "iostream"

using namespace std;

int main(void)
{
	int control;
	double a, b;

	while (true)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "MENU:\n0 - exit\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\nYour choice ? ";
		cin >> control;

		if (control == 0) break;

		cout << "a = ";
		cin >> a;

		cout << "b = ";
		cin >> b;

		switch (control)
		{
		case 1:
			cout << "a + b = " << a + b << endl;
			break;
		case 2:
			cout << "a - b = " << a - b << endl;
			break;
		case 3:
			cout << "a * b = " << a * b << endl;
			break;
		case 4:
			if (b != 0) cout << "a / b = " << a / b << endl;
			break;
		}
	}

	system("pause");
	return 0;
}