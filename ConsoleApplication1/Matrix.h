#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(unsigned int rows, unsigned int cols);
	Matrix(const Matrix& m);

	~Matrix();

	void Print();
	void FillRandom(int a, int b);
	void FillRandom(double a, double b);

	Matrix operator+ (const Matrix& right);
	Matrix operator- (const Matrix& right);
	Matrix operator* (const Matrix& right);
	Matrix operator* (const double right);
	Matrix& operator= (const Matrix& right);


	bool operator == (const Matrix& right);
	bool operator != (const Matrix& right);

	friend Matrix operator* (const double left, Matrix right);

	// Ёлементарные преобразовани€ матриц
	//		”множение строки на число отличное от нул€,
	//		ѕрибавление одной строки к другой строке,
	//		ѕерестановка местами двух строк.
	void Row_mult(size_t row, double n);
	void Row_add(size_t row1, size_t row2, double k = 1);
	void Row_change(size_t row1, size_t row2);
	void Clear();


private:
	double** matrix;
	unsigned int rows;
	unsigned int cols;
};