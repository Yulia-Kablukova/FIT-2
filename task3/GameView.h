#pragma once
#include <iostream>
#include "GameModel.h"

class GameView : GameObserver
{
	std::unique_ptr<GameModel> *model;
public:
	GameView(std::unique_ptr<GameModel> *_model);
	void update();
	void startMessage();
	void numberOfPlayersMessage();
	void getNumber(int player);
	void badNumberMessage();
	void whoStartsMessage(int player);
	void requestAnswerMessage(int player);
	void resultsMessage();
	void winMessage();
};
