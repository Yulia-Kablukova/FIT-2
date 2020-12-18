#pragma once
#include <iostream>
#include <cstdlib>
#include "GameModel.h"
#include "GameView.h"
#include "GameObserver.h"
#include "Bot.h"

class GameController : GameObserver
{
	GameModel* model;
	GameView* view;
public:
	GameController(GameModel* _model, GameView* _view);
	~GameController();

	void update();

	void start();
	void twoPlayers();
	void onePlayer();
	bool checkAnswer(std::string answer);
};
