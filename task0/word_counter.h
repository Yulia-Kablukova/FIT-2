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
	void sortMap(std::map <int, std::list<std::string>> &orderedMap);
	void print(std::map <int, std::list<std::string>> &orderedMap, std::ofstream &file);
};


int isSymbol(char *symb);
void insertInList(std::map <int, std::list<std::string>> &orderedMap, std::map <std::string, int>::iterator &it);
