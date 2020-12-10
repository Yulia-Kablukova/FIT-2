#pragma once
#include <list>
#include "Context.h"
#include <iostream>
#include "Exceptions.h"

class Operation {
public:
	virtual void execute(const std::list<std::string>& args, Context& ctx) const = 0;
	virtual ~Operation() {};
};
