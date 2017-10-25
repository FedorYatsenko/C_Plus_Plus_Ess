#include <iostream>

using namespace std;

int main(void) 
{
	unsigned short int val, index1 = 1, index2 = 32768;
	bool ispalindrome = true;

	cout << "value = ";
	cin >> val;

	while (index1 < index2)
	{
		if (!(((val & index1) && (val & index2)) || (!(val & index1) && !(val & index2)))) ispalindrome = false;

		index1 <<= 1;
		index2 >>= 1;
	}
	
	if (ispalindrome)
		cout << val << " is a bitwise palindrome" << endl;
	else
		cout << val << " is not a bitwise palindrome" << endl;
	
	system("pause");
	return 0;
}