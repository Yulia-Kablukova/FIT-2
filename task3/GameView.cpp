#include "GameView.h"

void GameView::startMessage()
{
	std::cout << "Добро пожаловать!\nВведите количество игроков:" << std::endl;
}

void GameView::numberOfPlayersMessage()
{
	std::cout << "Игра расчитана на 1 или 2 игрока!" << std::endl;
}

void GameView::getNumber(int player)
{
	std::cout << "Игрок" << player << ", загадайте число: " << std::endl;
}

void GameView::badNumberMessage()
{
	std::cout << "Введите число из 4 неповторяющихся цифр!" << std::endl;
}

void GameView::randomResultMessage(int player)
{
	std::cout << "Игрок" << player << " ходит первым!" << std::endl;
}

void GameView::requestAnswer(int player)
{
	std::cout << "\nИгрок" << player << ": " << std::endl;
}

void GameView::resultsMessage(int bulls, int cows)
{
	std::cout << "Быков: " << bulls << ", коров: " << cows << std::endl;
}

void GameView::winMessage(int player)
{
	std::cout << "\nИГРОК" << player << " ПОБЕДИЛ!" << std::endl;
}
