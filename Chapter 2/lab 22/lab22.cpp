#include <iostream>

using namespace std;

int main(void)
{
	int n;
	unsigned long long int result = 1;

	cout << "Enter value of n: ";
	cin >> n;

	if (n > 0)
	{
		for (int i = 2; i <= n; i++)
			result *= i;

		cout << "Result: " << result << endl;
	}

	system("pause");
	return 0;
}