#include "GameModel.h"

GameModel::GameModel()
{
	turn = rand() % 2 + 1;
	gameOver = 0;
}

void GameModel::setNumber(std::string number, int player)
{
	std::get<0>(players[player - 1]) = number;
}

void GameModel::setAnswer(std::string answer)
{
	int player = getTurn();

	std::get<1>(players[player - 1]) = answer;
	std::get<2>(players[player - 1]) = bullsNumber(player);
	std::get<3>(players[player - 1]) = cowsNumber(player);

	if (std::get<2>(players[player - 1]) == 4) gameOver = 1;
	
	notifyObservers();
	
	changeTurn();
}

void GameModel::changeTurn()
{
	turn = (turn % 2) + 1;
}

int GameModel::getTurn()
{
	return turn;
}

int GameModel::getBulls()
{
	return std::get<2>(players[getTurn() - 1]);
}

int GameModel::getCows()
{
	return std::get<3>(players[getTurn() - 1]);
}

int GameModel::bullsNumber(int player)
{
	int bulls = 0;
	std::string correctAnswer = std::get<0>(players[player % 2]);
	std::string checkingAnswer = std::get<1>(players[player - 1]);

	for (int i = 0; i < 4; i++)
	{
		if (correctAnswer[i] == checkingAnswer[i]) bulls++;
	}

	return bulls;
}

int GameModel::cowsNumber(int player)
{
	int cows = 0;
	std::string correctAnswer = std::get<0>(players[player % 2]);
	std::string checkingAnswer = std::get<1>(players[player - 1]);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j && correctAnswer[i] == checkingAnswer[j]) cows++;
		}
	}

	return cows;
}

bool GameModel::isGameOver()
{
	return gameOver;
}
