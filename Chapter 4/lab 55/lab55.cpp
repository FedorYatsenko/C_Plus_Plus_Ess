#include <string>
#include <iostream>

using namespace std;

int main()
{
	bool anagrams = true;

	string word1 = "",
		word2 = "";
	
	int i = 0;

	cin >> word1;
	cin >> word2;

	for (int i = 0; i < word2.length(); i++)
		if (word1.find_first_of(word2[i]) == string::npos )
			anagrams = false;

	for (int i = 0; i < word1.length(); i++)
		if (word2.find_first_of(word1[i]) == string::npos)
			anagrams = false;

	if (anagrams) cout << "anagrams" << endl;
	else cout << "not anagrams" << endl;

	system("pause");
}