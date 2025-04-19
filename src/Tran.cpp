#include "Tran.h"

Matrix Tran::execute(const Matrix& matrix, float num) const
{
	Matrix ansMatrix(matrix.getSize());

	for (int row = 0 ; row < matrix.getSize(); row++)
	{
		for (int col = 0 ; col < matrix.getSize(); col++)
		{
			ansMatrix(col, row) = matrix(row, col);
		}
	}
	return ansMatrix;
}