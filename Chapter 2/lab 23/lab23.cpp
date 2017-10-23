#include <iostream>

using namespace std;

int main(void)
{
	unsigned int side;
	int result;

	cout << "Input side: ";
	cin >> side;

	if (side % 2 != 0)
	{
		result = side * side - (side*side - (side - 2)*(side - 2)) / 2;
		cout << "Result: " << result << endl;
	}

	system("pause");
	return 0;
}