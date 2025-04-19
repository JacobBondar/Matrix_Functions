#include <BasicOperation.h>

//-----------------------------------------------------------------------------

std::string BasicOperation::getName() const
{
    std::string temp;
    temp = m_name;
    return temp;
}

//-----------------------------------------------------------------------------

Matrix BasicOperation::calcFunc(int size, Matrix& prevMatrix, bool comp) const
{
	Matrix matrix(size);
	float scalNum = m_scalNum;

	// If the operator is a comparison operator, we don't need to get the 
	//  matrix from the user, as we already have it.
    if (comp) matrix = prevMatrix;
    else std::cin >> matrix;

    return m_function->execute(matrix, scalNum);
}