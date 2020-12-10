#include "Calculator.h"
#include "OperationFactory.h"
#include "OperationMaker.h"

void Calculator::calculate(std::istream& stream)
{
	Context ctx;
	std::string line;
	std::string command;
	while (std::getline(stream, line))
	{
		command = "";
		unsigned int i = 0;
		while (line[i] != ' ' && i < line.size()) command += line[i++];

		if (command == "#") continue;

		i++;
		std::string arg;
		std::list<std::string> args;
		while (i < line.size())
		{
			arg += line[i++];
			if (line[i] == ' ' || i == line.size())
			{
				args.push_back(arg);
				arg = "";
			}
		}

		std::unique_ptr<Operation> operation(OperationFactory::getInstance().getOperation(command));
		operation->execute(args, ctx);
	}
}
