#include <string>
#include <iostream>

using namespace std;


bool NextWord(string &key, string &value, string sentence, int &endWord)
{
	if (endWord >= sentence.length()) return false;

	key = "";
	value = "";

	for (; endWord < sentence.length() && sentence[endWord] != '='; endWord++)
		key += sentence[endWord];

	for (endWord++; endWord < sentence.length() && sentence[endWord] != ','; endWord++)
		value += sentence[endWord];

	endWord++;

	return true;
}

int main()
{
	string values;
	getline(cin, values);
	
	string templ;
	getline(cin, templ);

	string key = "",
		value = "";

	int endWord = 0,
		pos;

	while (NextWord(key, value, values, endWord))
	{
		while ((pos = templ.find("[" + key + "]")) != string::npos)
		{
			templ.replace(pos, key.length() + 2, value);
		}
	}

	cout << templ << "\n";

	system("pause");
}