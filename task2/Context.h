#pragma once
#include <stack>
#include <map>
#include <string>
#include <iostream>

class Context {
	std::stack<double> stack;
	std::map<std::string, double> vars;
public:
	int stackSize();
	void pushValue(double value);
	double popValue();
	void printTop();
	void addVar(std::string key, double definition);
	bool find(std::string key);
	double getValue(std::string key);
};
