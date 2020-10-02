#include "word_counter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <iomanip> 

void WordCounter::readFile(const std::string &fileName)
{
	std::ifstream file;

	file.open(fileName);
	if (!file)
	{
		throw "Can't open the file";
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
		throw "Can't open the file";
	}

	if (wordCount == 0)
	{
		file.close();
		return;
	}

	std::map <int, std::list<std::string>> orderedMap;

	sortMap(orderedMap);

	print(orderedMap, file);

	file.close();
}

void WordCounter::sortMap(std::map <int, std::list<std::string>> &orderedMap)
{
	for (std::map <std::string, int>::iterator it = wordMap.begin(); it != wordMap.end(); ++it)
	{
		if (orderedMap[it->second].empty())
		{
			orderedMap[it->second].push_back(it->first);
		}
		else
		{
			insertInList(orderedMap, it);
		}
	}
}

void insertInList(std::map <int, std::list<std::string>> &orderedMap, std::map <std::string, int>::iterator &it)
{
	for (std::list<std::string>::iterator i = orderedMap[it->second].begin(); i != orderedMap[it->second].end(); ++i)
	{
		if (*i > it->first)
		{
			orderedMap[it->second].emplace(i, it->first);
			return;
		}
	}

	orderedMap[it->second].emplace_back(it->first);
}

void WordCounter::print(std::map <int, std::list<std::string>> &orderedMap, std::ofstream &file)
{
	for (std::map <int, std::list<std::string>>::iterator it = --orderedMap.end(); it != --orderedMap.begin(); --it)
	{
		for (std::list<std::string>::iterator i = it->second.begin(); i != it->second.end(); ++i)
		{
			file << *i << ";" << it->first << ";" << std::fixed << std::setprecision(2) << ((double)it->first / wordCount * 100) << " %" << std::endl;
		}
	}
}
