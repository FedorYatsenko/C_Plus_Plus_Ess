#include "iostream"

using namespace std;

int main(void)
{
	int amount;

	const int countBanknotes = 5;
	int banknotes[countBanknotes] = { 50, 20, 10, 5, 1 };

	cout << "Enter amount of money: ";
	cin >> amount;

	int count;
	for (int i = 0; i < countBanknotes; i++)
	{
		count = amount / banknotes[i];
		amount -= count * banknotes[i];

		for (int j = 0; j < count; j++)
			cout << banknotes[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}