#pragma once

#include <iostream>
#include "Action.h"

class Add : public Action
{
public:
    Add() = default;
    virtual ~Add() = default;

    virtual Matrix calcAction(int size, Matrix& prevMatrix, bool comp,
                              const std::shared_ptr<Operation> firstOperation,
                              const std::shared_ptr<Operation> secondOperation) const override;
};