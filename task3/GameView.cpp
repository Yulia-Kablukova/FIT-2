#include "GameView.h"

GameView::GameView(std::unique_ptr<GameModel> *_model)
{
	model = std::move(_model);
	model->get()->addObserver(this);
}

void GameView::update()
{
	resultsMessage();
	if (model->get()->isGameOver()) winMessage();
}

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

void GameView::whoStartsMessage(int player)
{
	std::cout << "Игрок" << player << " ходит первым!" << std::endl;
}

void GameView::requestAnswerMessage(int player)
{
	std::cout << "\nИгрок" << player << ": " << std::endl;
}

void GameView::resultsMessage()
{
	std::cout << "Быков: " << model->get()->getBulls() << ", коров: " << model->get()->getCows() << std::endl;
}

void GameView::winMessage()
{
	std::cout << "\nИГРОК" << model->get()->getTurn() << " ПОБЕДИЛ!" << std::endl;
}
