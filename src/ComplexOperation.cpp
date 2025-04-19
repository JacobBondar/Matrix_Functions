#include <ComplexOperation.h>

//-----------------------------------------------------------------------------

std::string ComplexOperation::getName() const
{
    std::string temp;
    temp = m_name;
    return temp;
}

//-----------------------------------------------------------------------------

// This function is used to calculate the result of the complex operation,
// depending on the action that is being performed. The calculations are done 
// by recursively calling the calcFunc function of the two operations that are
// part of the complex operation.
// The comp value stores the information if the operation is a composition of
// two operations. If it is, the comp value is set to true, and the result of
// the first operation is stored in the ansMatrix. The second operation is then
// calculated using the result of the first operation as the previous matrix.
Matrix ComplexOperation::calcFunc(int size, Matrix& prevMatrix, bool comp) const
{
	std::shared_ptr<Operation> firstOperation = m_operation1;
    std::shared_ptr<Operation> secondOperation = m_operation2;

    return m_action->calcAction(size, prevMatrix, comp, firstOperation, secondOperation);
}