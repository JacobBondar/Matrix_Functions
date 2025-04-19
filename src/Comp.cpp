#include "Comp.h"
#include "Operation.h"

Matrix Comp::calcAction(int size, Matrix& prevMatrix, bool comp,
                        const std::shared_ptr<Operation> firstOperation,
                        const std::shared_ptr<Operation> secondOperation) const
{
    Matrix ansMatrix = firstOperation->calcFunc(size, prevMatrix, comp);
    comp = true;

    return secondOperation->calcFunc(size, ansMatrix, comp);
}