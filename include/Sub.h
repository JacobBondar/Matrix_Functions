#pragma once

#include "Action.h"
#include <iostream>

class Sub : public Action
{
public:
    Sub() = default;
    virtual ~Sub() = default;

    virtual Matrix calcAction(int size, Matrix& prevMatrix, bool comp,
                              const std::shared_ptr<Operation> firstOperation,
                              const std::shared_ptr<Operation> secondOperation) const override;
};