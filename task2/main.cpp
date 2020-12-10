#include <iostream>
#include <fstream>
#include "Calculator.h"

int main(int argc, char** argv)
{
	Calculator calculator;
	if (argc != 2)
	{
		calculator.calculate(std::cin);
	}
	else
	{
		std::ifstream fin;
		fin.open(argv[1]);

		if (!fin)
		{
			std::cout << "Can't open the file." << std::endl;
		}

		calculator.calculate(fin);
	}

	return 0;
}
