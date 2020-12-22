#include "GameController.h"

GameController::GameController(std::unique_ptr<GameModel> *_model, std::unique_ptr<GameView> *_view)
{
	model = std::move(_model);
	view = std::move(_view);
}

void GameController::start()
{
	view->get()->startMessage();

	int numberOfPlayers = requestNumberOfPlayers();
	system("cls");
	
	Player **players = new Player*[2];

	switch (numberOfPlayers)
	{
	case 2:
		players[0] = new Human;
		players[1] = new Human;
		break;
	case 1:
		players[0] = new Human;
		players[1] = new Bot;
		break;
	default:
		players[0] = new Bot;
		players[1] = new Bot;
		break;
	}
	
	requestNumber(players, 1);
	requestNumber(players, 2);

	system("cls");
	view->get()->whoStartsMessage(model->get()->getTurn());
	
	while (!model->get()->isGameOver())
	{
		requestAnswer(players, model->get()->getTurn());
	}

	delete[] players;
}

int GameController::requestNumberOfPlayers()
{
	int num;

	std::cin >> num;

	while (num > 2 || num < 0)
	{
		view->get()->numberOfPlayersMessage();
		std::cin >> num;
	}

	return num;
}

void GameController::requestNumber(Player** players, int player)
{
	view->get()->getNumber(player);

	std::string number = players[player - 1]->createNumber();
	while (!checkNumber(number))
	{
		view->get()->badNumberMessage();
		number = players[player - 1]->createNumber();
	}

	model->get()->setNumber(number, player);

	system("cls");
}

void GameController::requestAnswer(Player** players, int player)
{
	view->get()->requestAnswerMessage(player);

	std::string answer = players[player - 1]->guessAnswer();
	while (!checkNumber(answer))
	{
		view->get()->badNumberMessage();
		answer = players[player - 1]->guessAnswer();
	}

	model->get()->setAnswer(answer);
}

bool GameController::checkNumber(std::string number)
{
	if (number.size() != 4) return false;

	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (number[i] == number[j]) return false;
		}
	}

	return true;
}
