#include <iostream>
#include "GameModel.h"
#include "GameView.h"
#include "GameController.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	GameModel *model = new GameModel();
	GameView *view = new GameView(model);
	GameController *controller = new GameController(model, view);

	controller->start();

	return 0;
}
