#include <Matrix.h>

//-----------------------------------------------------------------------------

Matrix::Matrix(int size)
{
	for (int row =  0 ; row< size ; row++)
	{
		m_matrix.emplace_back(std::vector<float>());

		for (int col = 0 ;col < size ; col++)
		{
			int temp = 0;

			m_matrix[row].emplace_back(temp);
			m_matrix[row][col] = 0;
		}
	}
}

//-----------------------------------------------------------------------------

std::istream& operator>> (std::istream& is, Matrix& matrix)
{
	int temp = 0; 
	std::cout << "Enter a " << matrix.getSize() << "x" << matrix.getSize() 
													   << " matrix:\n";

	for (int row = 0 ; row < matrix.getSize(); row++)
	{
		for (int col = 0 ; col < matrix.getSize(); col++)
		{
			is >> temp;
			matrix(row , col) = temp;
		}
	}

	return is;
}

//-----------------------------------------------------------------------------

std::ostream& operator<< (std::ostream& os, const Matrix& matrix)
{
	std::cout << std::endl;

	for (int row = 0; row < matrix.getSize(); row++)
	{
		for (int col = 0; col < matrix.getSize(); col++)
		{
			os << matrix(row, col) << " ";
		}
		os << std::endl;
	}

	return os;
}

//-----------------------------------------------------------------------------

float& Matrix::operator()(unsigned int row, unsigned int col)
{
	checkValues(row, col);
	return m_matrix[row][col];
}

//-----------------------------------------------------------------------------

float Matrix::operator()(unsigned int row, unsigned int col) const
{
	checkValues(row, col);
	return m_matrix[row][col];
}

//-----------------------------------------------------------------------------

void Matrix::checkValues(unsigned int& row, unsigned int& col) const
{
	if (row >= getSize() || col >= getSize())
	{
		std::cerr << "You have exceeded the limits of the Matrix \n ";
		row = col = 0;
	}
}

//------------------------------------------------------------------------------

Matrix operator+(const Matrix& matrix1, const Matrix& matrix2)
{
	Matrix tempMatrix(matrix1.getSize());

	for (int row = 0 ; row < matrix1.getSize(); row++)
	{
		for (int col = 0 ; col < matrix1.getSize(); col++)
		{
			tempMatrix(row, col) = matrix1(row, col) + matrix2(row, col);
		}
	}

	return tempMatrix;
}

//-----------------------------------------------------------------------------

Matrix& operator+=(Matrix& matrix1, const Matrix& matrix2)
{
	matrix1 = matrix1 + matrix2;
	return matrix1;
}

//-----------------------------------------------------------------------------

Matrix operator* (float value, const Matrix& matrix)
{
	Matrix tempMatrix(matrix.getSize());

	for (int row = 0 ; row < matrix.getSize(); row++)
	{
		for (int col = 0 ;col < matrix.getSize(); col++)
		{
			tempMatrix(row, col) = matrix(row, col) * value;
		}
	}

	return tempMatrix;
}
