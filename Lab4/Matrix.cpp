#include "Matrix.h"
#include <iomanip>

Matrix::Matrix() {
	row = 0;
	column = 0;
	elements = nullptr;
}
Matrix::Matrix(int input_row, int input_column) {
	row = input_row;
	column = input_column;
	elements = new double* [input_row];
	for (int i = 0; i < input_row; i++)	
		elements[i] = new double[input_column];
	for (int i = 0; i < input_row; i++)
		for (int j = 0; j < input_column; j++)
			elements[i][j] = 0;
}
Matrix::Matrix(int input_row, int input_column, int* arr) {
	row = input_row;
	column = input_column;
	elements = new double* [input_row];
	for (int i = 0; i < input_row; i++)
		elements[i] = new double[input_column];
	int k = 0;
	for (int i = 0; i < input_row; i++)
		for (int j = 0; j < input_column; j++) {
			elements[i][j] = arr[k];
			k++; 
		}	
}
Matrix::Matrix(const Matrix& obj) {
	row = obj.row;
	column = obj.column;
	if (obj.elements == nullptr) {
		elements = nullptr;
		
	} else {
		elements = new double* [row];
		for (int i = 0; i < row; i++)
			elements[i] = new double[column];
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				elements[i][j] = obj.elements[i][j];
	}
}
Matrix::~Matrix() {
	if (elements != nullptr) {
		for (int i = 0; i < row; i++)
			delete[] elements[i];
		delete[] elements;
	}
}
void Matrix::setValueAt(double val, unsigned int r, unsigned int c) {
	if ((r < row)&&(c < column)) elements[r][c] = val;
}

void Matrix::inputMatrix() {
	int r, c = 0;
	std::cout << "Rows: ";
	std::cin >> r;
	std::cout << "Columns: ";
	std::cin >> c;
	Matrix temp(r, c);
	if ((temp.row != 0) || (temp.column != 0)) {
		for (int i = 0; i < temp.row; i++)
			for (int j = 0; j < temp.column; j++) {
				std::cout << "[" << i << "] " << "[" << j << "]: ";
				std::cin >> temp.elements[i][j];
			}
	}
	*this = temp;
}
Matrix operator-(const Matrix& obj) {
	for (int i = 0; i < obj.row; i++)
		for (int j = 0; j < obj.column; j++) {
			if (obj.elements[i][j] != 0) obj.elements[i][j] *= -1;
		}	
	return obj;
}
Matrix Matrix::operator+(const Matrix& obj) {
	if ((row != obj.row) || (column != obj.column)) return *this;
	Matrix temp(*this);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) 
			temp.elements[i][j] += obj.elements[i][j];
	return temp;
}
Matrix Matrix::operator-(const Matrix& obj) {
	if ((row != obj.row) || (column != obj.column)) return *this;
	Matrix temp(*this);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			temp.elements[i][j] -= obj.elements[i][j];
	return temp;
}
Matrix Matrix::operator * (double b) {
	Matrix temp(row, column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			temp.elements[i][j] = elements[i][j] * b;
	return temp;
}
Matrix Matrix::operator * (Matrix& obj) {
	if (column == obj.row) {
		Matrix temp(row, obj.column);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < obj.column; j++)
				for (int k = 0; k < column; k++)
					temp.elements[i][j] += (elements[i][k] * obj.elements[k][j]);
		return temp;
	} else {
		throw "Matrix of such sizes cannot be multiplied";
	}
}
Matrix operator*(double b, const Matrix& obj) {
	Matrix temp(obj.row, obj.column);
	for (int i = 0; i < obj.row; i++)
		for (int j = 0; j < obj.column; j++)
			temp.elements[i][j] = obj.elements[i][j] * b;
	return temp;
}
Matrix& Matrix::operator=(const Matrix& obj) {
	if ((row != obj.row) || (column != obj.column)) {
		for (int i = 0; i < row; i++)
			delete[] elements[i];
		delete[] elements;
		row = obj.row;
		column = obj.column;
		elements = new double* [row];
		for (int i = 0; i < row; i++)
			elements[i] = new double[column];
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			elements[i][j] = obj.elements[i][j];
	return *this;
}
double& Matrix::at(const unsigned int r, const unsigned int c) {
	if ((r < row) && (c < column)) {
		return elements[r][c];
	} else {
		throw std::logic_error("out of bounds");
	}
}
Matrix Matrix::operator!() {
	Matrix temp(column, row);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			temp.elements[j][i] = elements[i][j];
	return temp;
}
Matrix Matrix::subMatrix(int sub_row, int sub_col) {
	Matrix temp(row - 1, column - 1);
	for (int i = 0; i < sub_row; i++) {
		for (int j = 0; j < sub_col; j++)
			temp.elements[i][j] = elements[i][j];
		for (int j = sub_col + 1; j < column; j++)
			temp.elements[i][j - 1] = elements[i][j];
	}
	for (int i = sub_row + 1; i < column; i++) {
		for (int j = 0; j < sub_col; j++)
			temp.elements[i - 1][j] = elements[i][j];
		for (int j = sub_col + 1; j < column; j++)
			temp.elements[i - 1][j - 1] = elements[i][j];
	}
	return temp;
}
double Matrix::determinant() {
	double det = 0;
	if (column == 1) return elements[0][0];
	Matrix temp(row - 1, column - 1);
	for (int j = 0; j < column; j++) {
		temp = subMatrix(0, j);
		if (j % 2 == 0) {
			det += temp.determinant() * elements[0][j];
		}
		else {
			det -= temp.determinant() * elements[0][j];
		}
	}
	return det;
}
Matrix Matrix::operator~() {
	if (column != row) throw 1;
	Matrix res(column, row);
	double det = determinant();
	if (det == 0) throw 2;
	int z;
	for (int i = 0; i < column; i++) {
		z = i % 2 == 0 ? 1 : -1;
		for (int j = 0; j < column; j++) {
			Matrix temp = subMatrix(i, j);
			res.elements[j][i] = std::round((z * temp.determinant() / det) * 100.0) / 100.0;
			z = -z;
		}
	}
	return res;
}
std::istream& operator>>(std::istream& in, Matrix& obj) {
	int r, c = 0;
	in >> r >> c;
	Matrix temp(r, c);
	obj = temp;
	for (int i = 0; i < obj.row; i++)
		for (int j = 0; j < obj.column; j++)
			in >> obj.elements[i][j];
	return in;
}
std::ostream& operator<<(std::ostream& out, const Matrix& obj) {
	if (obj.elements != nullptr) {
		out << "Matrix:" << std::endl;
		for (int i = 0; i < obj.row; i++)
		{
			for (int j = 0; j < obj.column; j++)
				out << std::setw(7) << obj.elements[i][j];
			out << std::endl;
		}
	} else {
		out << "Matrix is empty" << std::endl;
	}
	return out;
}