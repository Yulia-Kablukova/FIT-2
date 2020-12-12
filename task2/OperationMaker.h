#pragma once
#include "IOperationMaker.h"
#include "OperationFactory.h"

template<typename T>
class OperationMaker : public IOperationMaker
{
public:
    OperationMaker(const std::string& command)
    {
        OperationFactory::getInstance().registerMaker(command, this);
    }

    virtual Operation* getOperation(const std::string& command) const
    {
        return new T();
    }
};
