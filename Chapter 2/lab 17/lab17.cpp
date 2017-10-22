#include <iostream>

using namespace std;

int main(void)
{
	int pow;
	unsigned long long int result = 1;

	cout << "Input powers: ";
	cin >> pow;

	if (pow < 64)
	{
		for (int i(0); i < pow; i++)
			result *= 2;

		cout << result << endl;
	}

	system("pause");
	return 0;
}