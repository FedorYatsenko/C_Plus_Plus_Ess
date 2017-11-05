#include <string>
#include <iostream>

using namespace std;

string NextWord(string sentence, int endWord)
{
	string word = "";
	int i = endWord;

	switch (sentence[endWord])
	{
	case ' ': i++;
		break;

	case ',': i += 2;
		break;
	}

	for (; i < sentence.length() && sentence[i] != ' ' && sentence[i] != ','; i++)
		word += sentence[i];

	return word;
}

int main()
{
	string sentence;
	getline(cin, sentence);
	sentence = " " + sentence;

	string word = "",
		nextword = "";

	int endWord = 0;


	while ((nextword = NextWord(sentence, endWord)) != "")
	{
		if (sentence[endWord] == ',')
			endWord += nextword.length() + 2;
		else
			if (nextword == word)
				sentence.erase(endWord, nextword.length() + 1);
			else
				endWord += nextword.length() + 1;

		word = nextword;
	}

	sentence.erase(0, 1);

	cout << sentence << "\n";
	system("pause");
}