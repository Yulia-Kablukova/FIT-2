#pragma once
#include "Operation.h"

class Pop : public Operation {
public:
	Pop() {}
	void execute(const std::list<std::string>& args, Context& ctx) const;
};
