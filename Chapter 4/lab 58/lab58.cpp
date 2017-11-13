#include <string>
#include <iostream>

using namespace std;

int main()
{
	string password;
	getline(cin, password);

	bool upperCase = false,
		lowerCase = false,
		digit = false,
		character = false;

	for (int i = 0; i < password.length(); i++)
		{
		if (password[i] >= 'A' && password[i] <= 'Z') upperCase = true;
		else if (password[i] >= 'a' && password[i] <= 'z') lowerCase = true;
		else if (password[i] >= '0' && password[i] <= '9') digit = true;
		else character = true;
		}

	if (password.length() < 8) cout << "The password must be 8 characters long" << endl;
	else if (upperCase && lowerCase && digit && character) cout << "The password is valid" << endl;

	if (!upperCase) cout << "The password must have at least one upper case letter" << endl;
	if (!lowerCase) cout << "The password must have at least one lower case letter" << endl;
	if (!digit) cout << "The password must have at least one digit" << endl;
	if (!character) cout <<	"The password must have at least one special character" << endl;

	system("pause");
	return 0;
}