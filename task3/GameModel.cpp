#include "GameModel.h"

void GameModel::setAnswer(std::string answer, int player)
{
	answers[player - 1] = answer;
	notifyObservers();
}

int GameModel::bullsNumber(std::string answer, int player)
{
	int bulls = 0;
	for (int i = 0; i < 4; i++)
	{
		if (answer[i] == answers[player % 2][i]) bulls++;
	}
	return bulls;
}

int GameModel::cowsNumber(std::string answer, int player)
{
	int cows = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j && answer[i] == answers[player % 2][j]) cows++;
		}
	}
	return cows;
}
