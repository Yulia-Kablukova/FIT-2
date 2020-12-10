#pragma once
#include "Operation.h"

class Sqrt: public Operation {
public:
	void execute(const std::list<std::string>& args, Context& ctx) const;
};
