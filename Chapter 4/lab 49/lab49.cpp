#include <iostream>  
#include <string> 

using namespace std;

int main(void)
{
	const int length = 'z' - 'a' + 1;
	int count[length] = { 0 };

	string inputString;

	cout << "Enter string: ";
	getline(cin, inputString);


	for (int i = 0; i < inputString.length(); i++)
		if (inputString[i] >= 'a' && inputString[i] <= 'z')	count[inputString[i] - (int)'a']++;
		else if (inputString[i] >= 'Z' && inputString[i] <= 'Z') count[inputString[i] - (int)'A']++;
	
	bool isPangram = true;

	for (int i = 0; i < length; i++)
		if (count[i] == 0) isPangram = false;

	cout << (isPangram ? "Pangram" : "Not pangram");
	cout << endl;

	for (char i = 'a'; i <= 'z'; i++)
		cout << i << "-" << count[(int)i - (int)'a'] << endl;

	system("pause");
	return 0;
}