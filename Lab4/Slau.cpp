#include "Slau.h"

Slau::Slau(int input_row, int input_column) {
	Matrix a(input_row, input_column);
	Matrix b(input_row, input_column);
	Matrix x(input_row, input_column);
	row = input_row;
	column = input_column;
	reoder = new int[column];
	for (int i = 0; i < column; i++)
		reoder[i] = i;
}
void Slau::kramer() {
	if (row != column) throw "NonSquareMatrix";
	double det = a.determinant();
	if (det == 0);
	rang = row;
	Matrix temp = a;
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < column; i++) 
			temp[i][j] = b[0][i];
		x[0][j] = temp.determinant();
		for (int i = 0; i < column; i++)
			temp[i][j] = a[i][j];
	}
	isSolved = true;
}
void Slau::inverseMatrix() {
	if (row != column);
	Matrix inverse = ~a;
	Matrix b = !(this->b);
	x = inverse * b;
	x = !x;
	rang = row;
	isSolved = true;
}
void Slau::jordanGauss() {
	Matrix A = a;
	Matrix B = b;
	int countOfNullCols = 0;
	for (int i = 0; i < row; i++) {
		if (A[i][i] != 0) {
			for (int k = 0; k < row; k++) {
				if (k == i) continue;
				double d = A[k][i] / A[i][i];
				for (int j = 0; j < column; j++)
					A[k][j] = A[k][j] - d * A[i][j];
				B[0][k] = B[0][k] - d * B[0][i];
			}
			for (int j = i + 1; j < column; j++)
				A[i][j] /= A[i][i];
			B[0][i] /= A[i][i];
			A[i][i] = 1;
		} else {
			int k;
			for (k = i + 1; k < row; k++)
				if (A[k][i] != 0) break;
			if (k == row) {
				if (i == column - 1 - countOfNullCols) {
					countOfNullCols++;
					break;
				}
				for (int j = 0; j < row; j++) {
					double t = A[j][i];
					A[j][i] = A[j][column - countOfNullCols - 1];
					A[j][column - countOfNullCols - 1] = t;
				}
				int t = reoder[i];
				reoder[i] = reoder[column - countOfNullCols - 1];
				reoder[column - countOfNullCols - 1] = t;
				countOfNullCols++;
				i--;
			} else {
				double* t = A[i];
				A[i] = A[k];
				A[k] = t;
				double p = B[0][i];
				B[0][i] = B[0][k];
				B[0][k] = p;
				i--;
			}
		}
	}
	rang = row < column - countOfNullCols ? row : column - countOfNullCols;
	int nullRows = row - rang;
	for (int i = rang; i < row; i++)
		if (B[0][i] != 0) {
			isSolved = false;
			return;
		}
	Matrix res(rang, 1 + column - rang);
	for (int i = 0; i < rang; i++) {
		res[i][0] = B[0][i];
		for (int j = rang; j < column; j++)
			res[i][j - rang + 1] = -A[i][j];
	}
	x = res;
	isSolved = true;
}
void Slau::solve(int numb = 1) {
	if (row == column) {
		if (numb == 1) kramer();
		else inverseMatrix();
	} else {
		jordanGauss();
	}
}

std::istream& operator >> (std::istream& in, Slau& obj) {
	std::cout << "Matrix of coeffs: ";
	in >> obj.a;
	std::cout << "Vector of free members: ";
	in >> obj.b;
	return in;
}
std::ostream& operator << (std::ostream& out, Slau& obj) {
	for (int i = 0; i < obj.row; i++) {
		for (int j = 0; j < obj.column; j++)
			out << obj.a[i][j] << "\t";
		out << "\t" << obj.b[0][i] << std::endl;
	}
	out << "Result of SLAU: " << std::endl;
	if (!obj.isSolved) {
		out << "System incomplete " << std::endl;
		return out;
	}
	if (obj.rang < obj.column) {
		for (int i = 0; i < obj.rang; i++) {
			out << "x" << (obj.reoder[i] + 1) << " = " << obj.x[i][0];
			for (int j = 1; j <= obj.column - obj.rang; j++) {
				if (obj.x[i][j] == 0) continue;
				if (obj.x[i][j] > 0) {
					out << "+" << obj.x[i][j] << "*x"
						<< (obj.reoder[obj.rang + j - 1] + 1);
				} else {
					out << obj.x[i][j] << "*x" 
						<< (obj.reoder[obj.rang + j - 1] + 1);
				}
				out << std::endl;
			}
		}
	} else {
		out << "{";
		for (int i = 0; i < obj.column - 1; i++)
			out << obj.x[0][i] << ", ";
		out << obj.x[0][obj.column - 1] << "}" << std::endl;
	}
}