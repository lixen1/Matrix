#include "Matrix.h"

Matrix::Matrix()
{
	rows = 0;
	cols = 0;
	matrix = nullptr;
}

Matrix::Matrix(unsigned int rows, unsigned int cols)
{
	this->rows = rows;
	this->cols = cols;

	matrix = new double* [rows];

	for (size_t i = 0; i < rows; ++i)
	{
		matrix[i] = new double[cols];
	}
}

Matrix::Matrix(const Matrix& m)
{
	rows = m.rows;
	cols = m.cols;

	if (!(cols > 0 && rows > 0))
		return;

	matrix = new double* [rows];
	for (size_t i(0); i < rows; ++i)
	{
		matrix[i] = new double[cols];

		for (size_t j(0); j < cols; ++j)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
}

Matrix::~Matrix()
{
	/*for (size_t i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix; */
}

void Matrix::Print()
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::FillRandom(int a, int b)
{
	for (size_t i(0); i < rows; ++i)
	{
		for (size_t j(0); j < cols; ++j)
		{
			matrix[i][j] = rand() % (abs(b - a) + 1) + a;
		}
	}
}

void Matrix::FillRandom(double a, double b)
{
	for (size_t i(0); i < rows; ++i)
	{
		for (size_t j(0); j < cols; ++j)
		{
			matrix[i][j] = (double)rand() / RAND_MAX * abs(b - a) + a;
		}
	}
}

void Matrix::Clear()
{
	for (size_t i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	cols = rows = 0;
}

void Matrix::Row_mult(size_t row, double n)
{
	for (int i(0); i < cols; ++i)
	{
		matrix[row][i] *= n;
	}
}

/* void Matrix::Row_add(size_t row1, size_t row2, double k = 1)
{
	if (k == 0)
	{
		return;
	}
	for (int i(0); i < cols; ++i)
	{
		matrix[row1][i] += matrix[row2][i] * k;
	}
}*/

void Matrix::Row_change(size_t row1, size_t row2)
{
	for (int i(0); i < cols; ++i)
	{
		swap(matrix[row1][i], matrix[row2][i]);
	}
}

//Matrix& Matrix::operator = (const Matrix& right) 
//{
//	Clear();
//
//}

bool Matrix::operator == (const Matrix& right) 
{
	if (rows != right.rows || cols != right.cols)
	{
		return false;
	}

	for (int i(0); i < cols; ++i)
	{
		for (int j(0); j < rows; ++j)
		{
			if (matrix[i][j] != right.matrix[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::operator != (const Matrix& right) 
{
	return !(*this == right);
}

Matrix Matrix::operator+(const Matrix& right)
{
	// check size left and right matrix

	Matrix* res = new Matrix(rows, cols);

	for (size_t i(0); i < rows; ++i)
	{
		res->matrix[i] = new double[cols];

		for (size_t j(0); j < cols; ++j)
		{
			res->matrix[i][j] = matrix[i][j] + right.matrix[i][j];
		}
	}
	return *res;
}

Matrix Matrix::operator-(const Matrix& right)
{
	// check size left and right matrix

	Matrix* res = new Matrix(rows, cols);

	for (size_t i(0); i < rows; ++i)
	{
		res->matrix[i] = new double[cols];

		for (size_t j(0); j < cols; ++j)
		{
			res->matrix[i][j] = matrix[i][j] - right.matrix[i][j];
		}
	}
	return *res;
}

Matrix Matrix::operator* (const Matrix& right)
{
	Matrix* res = new Matrix(rows, right.cols);

	for (size_t i(0); i < rows; ++i)
	{
		for (size_t j(0); j < right.cols; ++j)
		{
			for (size_t k(0); k < cols; k++)
			{
				res->matrix[i][j] += matrix[i][k] * right.matrix[k][j];
			}
		}
	}

	return *res;
}

Matrix Matrix::operator* (const double right)
{
	Matrix* res = new Matrix(rows, cols);

	for (size_t i(0); i < rows; ++i)
	{
		res->matrix[i] = new double[cols];

		for (size_t j(0); j < cols; ++j)
		{
			res->matrix[i][j] = matrix[i][j] * right;
		}
	}
	return *res;
}

Matrix operator* (const double left, Matrix right)
{
	return right * left;
}