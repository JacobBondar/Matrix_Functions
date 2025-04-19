#pragma once

#include <iostream>
#include "Matrix.h"

class Operation;

class Action
{
public:
    Action() = default;
    virtual ~Action() = default;

    virtual Matrix calcAction(int size, Matrix& prevMatrix, bool comp,
                              const std::shared_ptr<Operation> firstOperation,
                              const std::shared_ptr<Operation> secondOperation) const = 0 ;
};