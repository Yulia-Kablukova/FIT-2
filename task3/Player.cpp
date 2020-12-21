#include "Player.h"
#include <iostream>

std::string Human::createNumber()
{
	std::string number;

	std::cin >> number;

	return number;
}

std::string Human::guessAnswer()
{
	std::string number;

	std::cin >> number;

	return number;
}

std::string Bot::createNumber()
{
	std::string number = "";
	char tmp;
	int check;

	number += std::to_string(rand() % 10);
	for (int i = 1; i < 4; i++)
	{
		check = 0;
		while (!check)
		{
			tmp = (rand() % 10) + '0';
			check = 1;
			for (int j = 0; j < i; j++)
			{
				if (tmp == number[j])
				{
					check = 0;
					break;
				}
			}
		}
		number += tmp;
	}

	return number;
}

std::string Bot::guessAnswer()
{
	return createNumber();
}
