#include <string>
#include <iostream>

using namespace std;

bool CheckPattern(string word, string pattern)
{
	if (word.length() != pattern.length()) return false;

	for(int i = 0; i < pattern.length(); i++)
		switch (pattern[i])
		{
		case '?':
			break;
		case 'D':
			if (word[i] < '0' || word[i]>'9') return false;
			break;
		case 'A':
			if ((word[i] < 'a' || word[i]>'z') && (word[i] < 'A' || word[i]>'Z')) return false;
			break;
		case ',':
		case '-':
		case '!':
		case '@':
		case '#':
		case '$':
		case '%':
		case '^':
		case '&':
		case '*':
		case '(':
		case ')':
		case '+':
		case '=':
		case '"':
		case '¹':
		case ';':
		case ':':
		case '\'':
		case '\\':
		case '/':
		case '.':
			if (word[i] != pattern[i]) return false;
			break;
		default: if (pattern[i] >= 'a' && pattern[i] <= 'z' && tolower(word[i]) != pattern[i]);
				 else return false;
				 break;
		}

	return true;
}

int main()
{
	string pattern;
	getline(std::cin, pattern);
	string sentence;
	getline(std::cin, sentence);


	string nextWord;
	int length = sentence.length() - pattern.length() + 1;

	for (int i = 0; i < length; i++)
	{
		nextWord = sentence.substr(i, pattern.length());

		if (CheckPattern(nextWord, pattern)) cout << nextWord << endl;
	}
	
	system("pause");
}