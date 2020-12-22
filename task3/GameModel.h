#pragma once
#include <string>
#include <tuple>
#include "GameObserver.h"

class GameModel : public GameObservable
{
	std::tuple<std::string, std::string, int, int> players[2];
	int turn;
	int gameOver;
public:
	GameModel();
	void setNumber(std::string number, int player);
	void setAnswer(std::string answer);
	void changeTurn();
	int getTurn();
	int getBulls();
	int getCows();
	int bullsNumber(int player);
	int cowsNumber(int player);
	bool isGameOver();
};
