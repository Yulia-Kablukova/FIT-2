#include "word_counter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <iomanip>
#include <exception>

void WordCounter::readFile(const std::string &fileName)
{
	std::ifstream file;

	file.open(fileName);
	if (!file)
	{
		throw std::invalid_argument("Can't open the file");
	}

	std::string buffer;
	std::string str;

	while (std::getline(file, buffer))
	{
		std::transform(buffer.begin(), buffer.end(), buffer.begin(), tolower);

		for (unsigned int i = 0; i < buffer.length(); ++i)
		{
			if (isSymbol(&buffer[i]))
			{
				str += buffer[i];
			}
			else
			{
				saveWord(str);
			}
		}
	}

	file.close();
}

int isSymbol(char *symb)
{
	if (isdigit(*symb) || isalpha(*symb))
		return 1;
	return 0;
}

void WordCounter::saveWord(std::string &str)
{
	if (str != "")
	{
		str[0] = toupper(str[0]);
		wordCount++;
		wordMap[str]++;
		str = "";
	}
}

void WordCounter::printAnswer(const std::string &fileName)
{
	std::ofstream file;

	file.open(fileName);
	if (!file)
	{
		throw std::invalid_argument("Can't open the file");
	}

	if (wordCount == 0)
	{
		file.close();
		return;
	}

	std::list<std::pair<std::string, int>> wordList(wordMap.begin(), wordMap.end());
	wordList.sort(compare);

	print(wordList, file);

	file.close();
}

bool compare(const std::pair<std::string, int>&first, const std::pair<std::string, int>&second)
{
	if (first.second > second.second) return true;
	if (first.second < second.second) return false;

	unsigned int i;
	for (i = 0; i < first.first.length() && i < second.first.length(); i++)
	{
		if (first.first[i] < second.first[i]) return true;
		if (first.first[i] > second.first[i]) return false;
	}

	if (i == first.first.length()) return true;
	return false;
}

void WordCounter::print(std::list<std::pair<std::string, int>> &wordList, std::ofstream &file)
{
	for (std::list<std::pair<std::string, int>>::iterator it = wordList.begin(); it != wordList.end(); it++)
	{
		file << it->first << ";" << it->second << ";" << std::fixed << std::setprecision(2) << ((double)it->second / wordCount * 100) << " %" << std::endl;
	}
}
