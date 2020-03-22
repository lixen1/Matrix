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

	friend Matrix operator* (const double left, Matrix right);


private:
	double** matrix;
	unsigned int rows;
	unsigned int cols;
};