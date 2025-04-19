#pragma once

#include "Function.h"
#include <iostream>

class Scal : public Function
{
public:
    Scal() = default;
    virtual ~Scal() = default;

    virtual Matrix execute(const Matrix& matrix, float num)  const override 
                                                    { return num * matrix; };
};