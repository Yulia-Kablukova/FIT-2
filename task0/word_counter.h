#include <map>

class WordCounter
{
	std::map <std::string, int> wordMap;
	int wordCount;

public:
	WordCounter()
	{
		wordCount = 0;
	}
};
