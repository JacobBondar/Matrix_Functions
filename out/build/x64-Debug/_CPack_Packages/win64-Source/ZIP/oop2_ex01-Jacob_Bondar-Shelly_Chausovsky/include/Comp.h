#pragma once

#include "Action.h"
#include <iostream>

class Comp : public Action
{
public:
    Comp() = default;
    virtual ~Comp() = default;

    virtual Matrix calcAction(int size, Matrix& prevMatrix, bool comp,
                              const std::shared_ptr<Operation> firstOperation,
                              const std::shared_ptr<Operation> secondOperation) const override;
};