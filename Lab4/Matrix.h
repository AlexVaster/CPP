#pragma once
#include <iostream>

class Matrix {
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix& object);
	~Matrix();

	Matrix operator+(Matrix&);
	Matrix operator-(Matrix&);
	Matrix operator*(Matrix&);
	Matrix operator*(double);
	Matrix& operator=(Matrix&);
	double* operator[](int);
	Matrix operator!();
	friend Matrix operator*(double, Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend std::istream& operator>>(std::istream&, Matrix&);
private:
	int row, column;
	double** elements;
};

