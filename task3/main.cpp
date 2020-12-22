#include <iostream>
#include "GameModel.h"
#include "GameView.h"
#include "GameController.h"
#include <memory>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	std::unique_ptr<GameModel> model(new GameModel);
	std::unique_ptr<GameView> view(new GameView(&model));
	std::unique_ptr <GameController> controller(new GameController(&model, &view));

	controller->start();

	return 0;
}
