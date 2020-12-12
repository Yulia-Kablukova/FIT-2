#include "Sqrt.h"
#include "OperationMaker.h"
#include <iostream>

static OperationMaker<Sqrt> maker("SQRT");

void Sqrt::execute(const std::list<std::string>& args, Context& ctx) const {
	if (ctx.stackSize() < 1) {
		throw NotEnoughElementsInStackException();
	}

	double a = ctx.popValue();

	if (a < 0)
	{
		throw SqrtFromNegativeException();
	}

	ctx.pushValue(sqrt(a));
}
