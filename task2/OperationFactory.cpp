#include "OperationFactory.h"
#include "OperationMaker.h"

OperationFactory& OperationFactory::getInstance()
{
	static OperationFactory factory;
	return factory;
}

void OperationFactory::registerMaker(const std::string& command, IOperationMaker* maker)
{
	if (makers.find(command) != makers.end())
	{
		throw OperationAlreadyRegisteredException();
	}
	makers[command] = maker;
}

std::unique_ptr<Operation> OperationFactory::getOperation(const std::string& command) const
{
	auto i = makers.find(command);
	if (i == makers.end())
	{
		throw OperationNotFoundException();
	}

	IOperationMaker* maker = i->second;
	return std::unique_ptr<Operation>(maker->getOperation(command));
}
