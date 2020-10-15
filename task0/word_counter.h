#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <string>

class WordCounter
{
	std::map <std::string, int> wordMap;
	int wordCount;

public:
	WordCounter()
	{
		wordCount = 0;
	}

	void readFile(const std::string &fileName);
	void printAnswer(const std::string &fileName);

private:
	void saveWord(std::string &str);
	void print(std::list<std::pair<std::string, int>> &wordList, std::ofstream &file);
};

int isSymbol(char *symb);
bool compare(const std::pair<std::string, int>&first, const std::pair<std::string, int>&second);
