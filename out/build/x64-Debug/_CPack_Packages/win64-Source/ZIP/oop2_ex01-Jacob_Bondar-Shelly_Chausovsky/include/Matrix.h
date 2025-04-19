#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>

class Matrix 
{
public:
	Matrix(int size);
	unsigned int getSize() const { return m_matrix.size(); };
	float& operator()(unsigned int row, unsigned int col);
	float operator()(unsigned int row, unsigned int col) const;
	
private:
	std::vector<std::vector< float >> m_matrix;

	void checkValues(unsigned int& row, unsigned int& col) const;
};

//------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
std::istream& operator>>(std::istream& is, Matrix& matrix);

Matrix operator+(const Matrix& matrix1, const Matrix& matrix2);
Matrix& operator+=(Matrix& matrix1, const Matrix& matrix2);
Matrix operator*(float value, const Matrix& matrix);
