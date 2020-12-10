#pragma once
#include <iostream>
#include <map>
#include <string>
#include "IOperationMaker.h"
#include "Operation.h"

class OperationFactory
{
public:
	OperationFactory() {}

	static OperationFactory& getInstance();

	void registerMaker(const std::string& command, IOperationMaker* maker);

	std::unique_ptr<Operation> getOperation(const std::string& command) const;

private:
	OperationFactory(const OperationFactory& other);
	OperationFactory& operator=(const OperationFactory& other);

	std::map<std::string, IOperationMaker*> makers;
};
