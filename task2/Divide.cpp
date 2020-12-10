#include "Divide.h"
#include "OperationMaker.h"

static OperationMaker<Divide> maker("/");

void Divide::execute(const std::list<std::string>& args, Context& ctx) const {
	if (ctx.stackSize() < 2) {
		throw NotEnoughElementsInStackException();
	}

	double a = ctx.popValue();
	double b = ctx.popValue();

	if (b == 0) {
		throw DivisionByZeroException();
	}

	ctx.pushValue(a / b);
}
