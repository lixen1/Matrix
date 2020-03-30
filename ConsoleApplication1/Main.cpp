#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include "Matrix.h"

using namespace std;

// test egor branch

int main()
{
	srand(time(0));

	int n = 0;
	int m = 0;

	cin >> m >> n;

	Matrix m1;
	Matrix m2(m, n);
	Matrix m3(m, n);

	m2.FillRandom(10, 99);
	m3.FillRandom(10, 99);

	m2.Print();
	cout << endl;
	m3.Print();

	cout << endl;
	m1 = m2 + m3;
	m1.Print();

	cout << endl;
	m1 = m2 - m3;
	m1.Print();

	cout << endl;
	m1 = m2 * 0.5;
	m1.Print();

	cout << endl;
	m1 = 0.5 * m2;
	m1.Print();

	cout << endl;
	m1 = m2 * m3;
	m1.Print();

	return 0;
}