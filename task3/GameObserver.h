#pragma once
#include <list>

class GameObserver
{
public:
    virtual ~GameObserver() = default;
    virtual void update() = 0;
};

class GameObservable
{
	std::list<GameObserver*> observers;
public:
	void addObserver(GameObserver* observer)
	{
		observers.push_back(observer);
	}

	void removeObserver(GameObserver* observer)
	{
		observers.remove(observer);
	}

	void notifyObservers()
	{
		for (auto& observer : observers)
		{
			observer->update();
		}
	}
};
