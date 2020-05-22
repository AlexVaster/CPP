#pragma once
#include <iostream>

class Matrix {
public:
	Matrix();
	Matrix(int, int);
	Matrix(int, int, int*);
	Matrix(const Matrix& object);
	~Matrix();

	class TwoBracket {
	public:
		TwoBracket(double* arr) : arr(arr) { }
		double& operator[](int index) const { return arr[index]; }
	private:
		double* arr;
	};
	TwoBracket operator[](int index) const { return TwoBracket(elements[index]); }
	
	inline int getCountRow() const { return row; }
	inline int getCountCol() const { return column; }
	void setValueAt(double, int, int);
	void swapRow(Matrix&, int, int);

	void inputMatrix();
	friend Matrix operator-(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(Matrix&);
	Matrix operator*(double);
	friend Matrix operator*(double, const Matrix&);
	Matrix& operator=(const Matrix&);
	double& at(const int, const int);
	
	Matrix operator!();
	Matrix subMatrix(int, int);
	double determinant();
	Matrix operator~();
	
	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
private:
	friend class TwoBracket;
	int row, column;
	double** elements;
};

