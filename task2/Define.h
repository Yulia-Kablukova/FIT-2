#pragma once
#include "Operation.h"

class Define : public Operation {
public:
	Define() {}
	void execute(const std::list<std::string>& args, Context& ctx) const;
};
