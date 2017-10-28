#include "iostream"

using namespace std;

int main(void)
{
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13};
	int n = sizeof(vector) / sizeof(vector[0]);

	int *element = vector;
	int min = *element;

	element++;

	for (int index = 1; index < n; index++)
	{
		if (min > *element) min = *element;

		element++;
	}
	
	cout << "Min = " << min << endl;

	system("pause");
	return 0;
}