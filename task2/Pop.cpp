#include "Pop.h"
#include "OperationMaker.h"

static OperationMaker<Pop> maker("POP");

void Pop::execute(const std::list<std::string>& args, Context& ctx) const {
	if (ctx.stackSize() < 1) {
		throw NotEnoughElementsInStackException();
	}
	ctx.popValue();
}
