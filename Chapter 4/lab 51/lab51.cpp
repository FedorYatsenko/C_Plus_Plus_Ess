#include <string>
#include <iostream>

int main()
{
	std::string sentence;
	std::getline(std::cin, sentence);
	
	bool help = false;

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


	std::cout << sentence << "\n";
	system("pause");
}