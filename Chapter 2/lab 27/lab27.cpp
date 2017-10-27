#include <iostream>

using namespace std;

int main(void)
{
	const int length = 7;

	int vector1[length] = { 4, 7, 2, 8, 1, 3, 0 };
	int vector2[length];

	vector2[0] = vector1[length - 1];
	for (int i = 0; i < length - 1; i++)
		vector2[i + 1] = vector1[i];
	
	for (int i = 0; i < length; i++)
		cout << vector2[i] << ' ';
	cout << endl;
	
	system("pause");
	return 0;
}