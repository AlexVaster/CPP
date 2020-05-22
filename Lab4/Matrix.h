#pragma once
#include <iostream>

class Matrix {
public:
	Matrix();
	Matrix(int, int);
	Matrix(int, int, int*);
	Matrix(const Matrix& object);
	~Matrix();
	// Operator [][]
	class TwoBracketOperator {
	public:
		TwoBracketOperator(double* arr) : arr(arr) { }
		double& operator[](int index) const { return arr[index]; }
	private: 
		double* arr;
	};
	TwoBracketOperator operator[](int index) const { return TwoBracketOperator(elements[index]); }
	// Methods
	inline int getCountRow() const { return row; }
	inline int getCountCol() const { return column; }
	void setValueAt(double, int, int);
	void swapRow(Matrix&, int, int);
	Matrix& operator=(const Matrix&);
	double at(int, int);
	Matrix operator!(); // Transpose matrix
	Matrix subMatrix(int, int);
	double determinant();
	Matrix operator~(); // Inverse Matrix
	// Arithmetic
	friend Matrix operator-(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator*(double);
	friend Matrix operator*(double, const Matrix&);
	Matrix operator/(const Matrix&);
	// Logic
	bool operator==(const Matrix&);
	bool operator!=(const Matrix&);
	// I/O
	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
private:
	int row, column;
	double** elements;
};

