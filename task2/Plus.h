#pragma once
#include "Operation.h"

class Plus : public Operation {
public:
	Plus() {}
	void execute(const std::list<std::string>& args, Context& ctx) const;
};
