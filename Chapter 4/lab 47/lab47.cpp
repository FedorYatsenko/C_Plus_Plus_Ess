#include "iostream"
#include <iomanip>

using namespace std;

int main(void)
{
	long long int sum = 0;
	int N;

	cout << "Enter N = ";
	cin >> N;

	for (int i = 1; i <= N; i++)
		sum += i;

	cout << "sum = " << sum << endl;

	system("pause");
	return 0;
}