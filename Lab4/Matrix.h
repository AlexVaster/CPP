#pragma once
#include <iostream>

class Matrix {
public:
	Matrix();
	Matrix(int, int);
	Matrix(int, int, int*);
	Matrix(const Matrix& object);
	~Matrix();

	inline int getCountRow() const { return row; }
	inline int getCountCol() const { return column; }
	void setValueAt(double, unsigned int, unsigned int);

	void inputMatrix();
	friend Matrix operator-(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(Matrix&);
	Matrix operator*(double);
	friend Matrix operator*(double, const Matrix&);
	Matrix& operator=(const Matrix&);
	double& at(const unsigned int, const unsigned int);
	double* operator[](unsigned int index) const { return elements[index]; }
	
	Matrix operator!();
	Matrix subMatrix(int, int);
	double determinant();
	Matrix operator~();
	
	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
private:
	int row, column;
	double** elements;
};

