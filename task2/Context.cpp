#include "Context.h"
#include <iostream>

int Context::stackSize()
{
	return stack.size();
}

void Context::pushValue(double value)
{
	stack.push(value);
}

double Context::popValue()
{
	double value = stack.top();
	stack.pop();
	return value;
}

void Context::printTop()
{
	std::cout << stack.top() << std::endl;
}

void Context::addVar(std::string key, double definition)
{
	vars[key] = definition;
}

bool Context::find(std::string key)
{
	if (vars.find(key) == vars.end())
		return false;
	else return true;
}

double Context::getValue(std::string key)
{
	return vars[key];
}
