#pragma once
#include "Operation.h"

class Operation;

class IOperationMaker
{
public:
	//virtual IOperation* create(int* node) const = 0;
	virtual Operation* getOperation(const std::string& key) const = 0;

	virtual ~IOperationMaker() {}
};