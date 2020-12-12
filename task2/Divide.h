#pragma once
#include "Operation.h"

class Divide : public Operation {
public:
	void execute(const std::list<std::string>& args, Context& ctx) const;
};
