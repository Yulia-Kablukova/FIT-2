#include "Print.h"
#include "OperationMaker.h"

static OperationMaker<Print> maker("PRINT");

void Print::execute(const std::list<std::string>& args, Context& ctx) const {
	if (ctx.stackSize() < 1) {
		throw NotEnoughElementsInStackException();
	}
	ctx.printTop();
}
