#include <iostream>
#include <fstream>
#include <string>
#include "word_counter.h"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Incorrect data\n";
		return 0;
	}

	WordCounter *text = new WordCounter;
	
	try 
	{
		text->readFile(argv[1]);
		text->printAnswer(argv[2]);
	}
	catch(const char* exception)
	{
		std::cerr << "Error: " << exception << std::endl;
	}

	delete text;
	system("pause");
	return 0;
}
