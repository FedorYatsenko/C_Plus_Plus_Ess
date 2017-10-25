#include "iostream"

using namespace std;

int main(void)
{
	unsigned long int i;
	unsigned int count = 0;

	cout << "Enter integer: ";
	cin >> i;
	
	while (i != 0)
	{
		if (i & 1) count++;

		i = i >> 1;
	}

	cout << count << endl;
	
	system("pause");
	return 0;
}