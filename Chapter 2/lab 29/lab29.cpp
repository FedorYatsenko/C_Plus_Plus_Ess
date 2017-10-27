#include <iostream>

using namespace std;

int main(void)
{
	int vector[] = { 1, 7, 3, 8, 3, 7, 1 };
	bool ispalindrome = true;

	int n = sizeof(vector) / sizeof(vector[0]);

	int left = 0, right = n - 1;

	while (left < right)
	{
		if (vector[left] != vector[right]) ispalindrome = false;

		left++;
		right--;
	}

	if (ispalindrome)
		cout << "It's a palindrome";
	else
		cout << "It isn't a palindrome";
	cout << endl;

	system("pause");
	return 0;
}