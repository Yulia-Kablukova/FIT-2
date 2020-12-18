#pragma once
#include <string>
#include "GameObserver.h"

class GameModel : public GameObservable
{
	std::string answers[2];
public:
	GameModel(){}

	void setAnswer(std::string answer, int player);

	int bullsNumber(std::string answer, int player);

	int cowsNumber(std::string answer, int player);
};
