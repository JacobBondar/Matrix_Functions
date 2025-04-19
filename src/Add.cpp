#include "Add.h"
#include "Operation.h"

Matrix Add::calcAction(int size, Matrix& prevMatrix, bool comp,
                       const std::shared_ptr<Operation> firstOperation,
                       const std::shared_ptr<Operation> secondOperation) const
{
    Matrix ansMatrix(size);
    ansMatrix = firstOperation->calcFunc(size, prevMatrix, comp);
    comp = false;
    ansMatrix += secondOperation->calcFunc(size, prevMatrix, comp);
    return ansMatrix;
}