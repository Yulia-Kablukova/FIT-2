#pragma once
#include <iostream>
#include "GameModel.h"

class GameView
{
	GameModel *model;
public:
	GameView(GameModel *model) : model(model)
	{

	}

	~GameView()
	{
		delete model;
	}

	void startMessage();

	void numberOfPlayersMessage();

	void getNumber(int player);

	void badNumberMessage();

	void randomResultMessage(int player);

	void requestAnswer(int player);

	void resultsMessage(int bulls, int cows);

	void winMessage(int player);
};
