#include "GameController.h"

GameController::GameController(GameModel* _model, GameView* _view)
{
	model = _model;
	view = _view;
	model->addObserver(this);
}

GameController::~GameController()
{
	delete model;
	delete view;
}

void GameController::update()
{

}

void GameController::start()
{
	view->startMessage();

	int numOfPlayers;
	std::cin >> numOfPlayers;

	while (numOfPlayers > 2 || numOfPlayers < 0)
	{
		view->numberOfPlayersMessage();
		std::cin >> numOfPlayers;
	}

	system("cls");
	srand(time(NULL));

	if (numOfPlayers == 2)
	{
		twoPlayers();
	}

	if (numOfPlayers == 1)
	{
		onePlayer();
	}
}

void GameController::twoPlayers()
{
	std::string answer;
	int player = 1;

	view->getNumber(player);
	std::cin >> answer;
	while (!checkAnswer(answer))
	{
		view->badNumberMessage();
		std::cin >> answer;
	}
	model->setAnswer(answer, player);
	system("cls");

	player = 2;

	view->getNumber(player);
	std::cin >> answer;
	while (!checkAnswer(answer))
	{
		view->badNumberMessage();
		std::cin >> answer;
	}
	model->setAnswer(answer, player);
	system("cls");

	player = rand() % 2 + 1;
	view->randomResultMessage(player);

	while (1)
	{
		view->requestAnswer(player);
		std::cin >> answer;
		while (!checkAnswer(answer))
		{
			view->badNumberMessage();
			std::cin >> answer;
		}
		int bulls = model->bullsNumber(answer, player);
		view->resultsMessage(bulls, model->cowsNumber(answer, player));
		if (bulls == 4)
		{
			view->winMessage(player);
			break;
		}

		player = (player % 2) + 1;

		view->requestAnswer(player);
		std::cin >> answer;
		while (!checkAnswer(answer))
		{
			view->badNumberMessage();
			std::cin >> answer;
		}
		bulls = model->bullsNumber(answer, player);
		view->resultsMessage(bulls, model->cowsNumber(answer, player));
		if (bulls == 4)
		{
			view->winMessage(player);
			break;
		}

		player = (player % 2) + 1;
	}
}

void GameController::onePlayer()
{
	std::string answer;
	int player = 1;

	view->getNumber(player);
	std::cin >> answer;
	while (!checkAnswer(answer))
	{
		view->badNumberMessage();
		std::cin >> answer;
	}
	model->setAnswer(answer, player);
	system("cls");

	player = 2;
	Bot* bot = new Bot();

	answer = bot->createNumber();
	model->setAnswer(answer, player);

	player = rand() % 2 + 1;
	view->randomResultMessage(player);

	while (1)
	{
		if (player == 1)
		{
			view->requestAnswer(player);
			std::cin >> answer;
			while (!checkAnswer(answer))
			{
				view->badNumberMessage();
				std::cin >> answer;
			}
			int bulls = model->bullsNumber(answer, player);
			view->resultsMessage(bulls, model->cowsNumber(answer, player));
			if (bulls == 4)
			{
				view->winMessage(player);
				break;
			}

			player = 2;
		}
		else
		{
			view->requestAnswer(player);
			answer = bot->guessAnswer();
			std::cout << answer << std::endl;

			int bulls = model->bullsNumber(answer, player);
			view->resultsMessage(bulls, model->cowsNumber(answer, player));
			if (bulls == 4)
			{
				view->winMessage(player);
				break;
			}

			player = 1;
		}
	}

	delete bot;
}

bool GameController::checkAnswer(std::string answer)
{
	if (answer.size() != 4) return false;

	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (answer[i] == answer[j]) return false;
		}
	}

	return true;
}
