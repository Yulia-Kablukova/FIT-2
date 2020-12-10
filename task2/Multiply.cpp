#include "Multiply.h"
#include "OperationMaker.h"

static OperationMaker<Multiply> maker("*");

void Multiply::execute(const std::list<std::string>& args, Context& ctx) const {
	if (ctx.stackSize() < 2) {
		throw NotEnoughElementsInStackException();
	}
	ctx.pushValue(ctx.popValue() * ctx.popValue());
}
