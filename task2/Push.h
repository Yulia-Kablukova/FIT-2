#pragma once
#include "Operation.h"

class Push : public Operation {
public:
	Push() {}
	void execute(const std::list<std::string>& args, Context& ctx) const;
};
