#include "Push.h"
#include "OperationMaker.h"

static OperationMaker<Push> maker("PUSH");

void Push::execute(const std::list<std::string>& args, Context& ctx) const {
	if (args.size() != 1)
	{
		throw NotEnoughArgumentsException();
	}
	if (ctx.find(args.front()))
	{
		ctx.pushValue(ctx.getValue(args.front()));
	}
	else
	{
		double value;
		try
		{
			value = std::stod(args.front());
		}
		catch (std::exception)
		{
			throw UndefinedVariable();
		}
		ctx.pushValue(value);
	}
	
}
