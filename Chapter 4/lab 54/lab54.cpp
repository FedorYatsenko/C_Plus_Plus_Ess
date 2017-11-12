#include <string>
#include <iostream>

using namespace std;


string NextWord(string sentence, int endWord)
{
	string word = "";

	for (int i = endWord; i < sentence.length() && sentence[i] != ','; i++)
		word += sentence[i];

	return word;
}

int main()
{
	string stop_words;
	getline(cin, stop_words);
	string sentence;
	getline(cin, sentence);

	int pos = 0,
		endWord = 0;
	stop_words += ",";

	string helpSentence = " " + sentence + " ";
	for (int i = 0; i < helpSentence.length(); i++)
		helpSentence[i] = tolower(helpSentence[i]);

	string nextWord;

	while ((nextWord = NextWord(stop_words, endWord)) != "")
	{
		endWord += nextWord.length() + 1;

		while ((pos = helpSentence.find(" " + nextWord + " ")) != string::npos)
		{
			helpSentence.erase(pos + 1, nextWord.length());
			sentence.erase(pos, nextWord.length());
		}
	}

	bool help = true;

	for (int i = 0; i < sentence.length(); i++)
		if (sentence[i] != ' ') help = false;
		else
		{
			if (help)
			{
				sentence.erase(i, 1);
				i--;
			}

			help = true;
		}

	cout << sentence << "\n";
	system("pause");
}