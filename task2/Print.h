#pragma once
#include "Operation.h"

class Print : public Operation {
public:
	Print() {}
	void execute(const std::list<std::string>& args, Context& ctx) const;
};
