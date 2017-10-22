#include <iostream>

using namespace std;

int main(void)
{
	double result = 1;
	
	cout << "Input powers: ";
	int pow;

	cin >> pow;

	for (int i = 0; i < pow; i++)
		result /= 2;

	cout.precision(20);
	cout << result << endl;

	system("pause");
	return 0;
}