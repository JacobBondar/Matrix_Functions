#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

#include "Function.h"
#include "Action.h"

enum FunctionType
{
	ID,
	TRAN,
	SCAL
};

class Operation
{
public:
	Operation() = default;
	~Operation() = default;

	virtual void print() const = 0;
	virtual std::string getName() const = 0;
	virtual Matrix calcFunc(int size, Matrix& prevMatrix, bool comp) const = 0;
};