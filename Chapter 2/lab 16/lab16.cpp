#include <iostream>

using namespace std;

int main(void)
{
	double pi4 = 0.;
	long n;
	cout << "Number of iterations? ";
	cin >> n;

	double a = 1.0;

	for (double i(0); i < n; i++)
	{
		pi4 += 1 / a;
		if (a < 0)
			a = a * (-1) + 2;
		else
			a = (a + 2) * (-1);
	}

	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;

	system("pause");
	return 0;
}
