#include <iostream>

using namespace std;

int main(void)
{
	int num;
	unsigned long long int a, b = 1, c = 1;

	cout << "Enter number: ";
	cin >> num;

	for (int i = 3; i <= num; i++)
	{
		a = b;
		b = c;
		c = a + b;
	}

	cout << "Result: " << c << endl;

	system("pause");
	return 0;
}