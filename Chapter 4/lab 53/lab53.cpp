#include <string>
#include <iostream>

using namespace std;

bool equals(string sentence, int fromIndex, string s)
{
	if (fromIndex + s.length() > sentence.length()) return false;

	for (int i = 0; i < s.length(); i++)
		if (s[i] != sentence[fromIndex + i]) return false;

	return true;
}


int main()
{
	string from;
	getline(cin, from);
	string to;
	getline(cin, to);
	string sentence;
	getline(cin, sentence);

	for (int i = 0; i < sentence.length(); i++)
		if (equals(sentence, i, from))
		{
			sentence.replace(i, from.length(), to);
			i += to.length();
		}

	cout << sentence << "\n";
	system("pause");
}