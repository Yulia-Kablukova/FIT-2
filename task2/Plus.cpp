#include "Plus.h"
#include "OperationMaker.h"

static OperationMaker<Plus> maker("+");

void Plus::execute(const std::list<std::string>& args, Context& ctx) const {
	if(ctx.stackSize() < 2) {
		throw NotEnoughElementsInStackException();
	}
	ctx.pushValue(ctx.popValue() + ctx.popValue());
}
