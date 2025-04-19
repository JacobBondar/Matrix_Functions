#pragma once

#include "Function.h"
#include <iostream>

class Tran : public Function
{
public:
    Tran() = default;
    virtual ~Tran() = default;

    virtual Matrix execute(const Matrix& matrix, float num) const override;
};