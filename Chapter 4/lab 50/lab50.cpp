#include <iostream>
#include <string>

using namespace std;

string CheckIP(string ip)
{
	int count = 0;
	int parts = 0;
	ip = ip + ".";

	for (int i(0); i < ip.length(); i++)
	{
		if (ip[i] == '.' || i == ip.length() - 1)
		{
			if (count > 3) return "Too many characters in a part";

			if (stoi(ip.substr(i - count, count)) > 255) return "Too big a value of a part";

			if (parts++ > 3) return "Too many parts";

			count = -1;
		}

		if (ip[i] != '.' && !isdigit(ip[i])) return "Only digits and dots allowed";

		count++;
	}

	if (parts != 4) return "Incorrect parts count";

	return "Correct Ip";
}

int main(void)
{
	string ip;

	cout << "Enter ip: ";
	getline(cin, ip);

	cout << CheckIP(ip) << endl;

	system("pause");
	return 0;
}