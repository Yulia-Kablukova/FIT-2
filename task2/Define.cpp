#include "Define.h"
#include "OperationMaker.h"

static OperationMaker<Define> maker("DEFINE");

void Define::execute(const std::list<std::string>& args, Context& ctx) const {
	if (args.size() != 2)
	{
		throw NotEnoughArgumentsException();
	}
	ctx.addVar(args.front(), std::stod(args.back()));
}
