#include "iostream"

using namespace std;

int main(void)
{
	unsigned int c0, count = 0;
	cout << "c0 = ";
	cin >> c0;

	if (c0 != 0)
		while (c0 != 1)
		{
			if (c0 % 2 == 0)  c0 /= 2;
			else c0 = 3 * c0 + 1;

			cout << c0 << endl;

			count++;
		}

	cout << "steps = " << count << endl;

	system("pause");
	return 0;
}