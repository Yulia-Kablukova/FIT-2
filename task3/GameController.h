#pragma once
#include <iostream>
#include <cstdlib>
#include "GameModel.h"
#include "GameView.h"
#include "Player.h"

class GameController
{
	std::unique_ptr<GameView> *view;
	std::unique_ptr<GameModel> *model;
public:
	GameController(std::unique_ptr<GameModel> *_model, std::unique_ptr<GameView> *_view);
	void start();
	int requestNumberOfPlayers();
	void requestNumber(Player** players, int player);
	void requestAnswer(Player** players, int player);
	bool checkNumber(std::string number);
};
