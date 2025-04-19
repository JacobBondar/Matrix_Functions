#pragma once

#include "Function.h"
#include <iostream>

class Id : public Function
{
public:
    Id() = default;
    virtual ~Id() = default;

    virtual Matrix execute(const Matrix& matrix, float num)  const override { return matrix; };
};