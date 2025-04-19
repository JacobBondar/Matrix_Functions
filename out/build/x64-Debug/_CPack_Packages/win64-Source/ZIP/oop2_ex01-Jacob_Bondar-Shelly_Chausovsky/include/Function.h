#pragma once

#include "Matrix.h"

class Function
{
public:
    Function() = default;
    virtual ~Function() = default; // Virtual destructor for proper cleanup of derived classes

    virtual Matrix execute(const Matrix& matrix, float num) const = 0; // Pure virtual function
};