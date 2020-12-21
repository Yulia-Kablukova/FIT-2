#pragma once
#include <string>
#include <cstdlib>

class Player
{
public:
	virtual std::string createNumber() = 0;
	virtual std::string guessAnswer() = 0;
	virtual ~Player() {};
};

class Human : public Player
{
public:
	std::string createNumber();
	std::string guessAnswer();
};

class Bot : public Player
{
public:
	std::string createNumber();
	std::string guessAnswer();
};
