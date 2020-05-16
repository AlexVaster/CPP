#include "Matrix.h"

Matrix::Matrix() {
	row = 0;
	column = 0;
	elements = nullptr;
}
Matrix::Matrix(int input_row, int input_column) {
	elements = new double* [input_row];
	for (int i = 0; i < input_row; i++)	
		elements[i] = new double[input_column];
	for (int i = 0; i < input_row; i++)
		for (int j = 0; j < input_column; j++)
			elements[input_row][input_column] = 0;
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