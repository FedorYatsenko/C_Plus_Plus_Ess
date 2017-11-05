#include <iostream>
#include <string>
using namespace std;

void up(string &s, int begin, int end)
{
	for(int i = begin; i < end; i++)
		s[i] = toupper(s[i]);
}

void add(string &s, int begin, int end)
{
	for (int i = end-1; i > begin; i--)
		s.insert(i, " ");
}

int main(void)
{
	string sentence;
	getline(cin, sentence);

	bool asterisk = false,
		underscore = false;

	int index = 0;

	for (int i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] == '*')
		{
			underscore = false;

			if (asterisk)
			{
				up(sentence, index, i);
				asterisk = false;
			}
			else
			{
				index = i;
				asterisk = true;

			}
		}

		if (sentence[i] == '_')
		{
			asterisk = false;

			if (underscore)
			{
				add(sentence, index, i);
				underscore = false;				
			}
			else
			{
				index = i;
				underscore = true;

			}
		}
	}

	for (int i = 0; i < sentence.length(); i++)
		if (sentence[i] == '*' || sentence[i] == '_')
		{
			sentence.erase(i, 1);
			i--;
		}

	cout << sentence << '\n';

	system("pause");
	return 0;
}