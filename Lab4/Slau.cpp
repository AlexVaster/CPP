#include "Slau.h"
#include <iomanip>

Slau::Slau() {
	Matrix a;
	Matrix b;
	Matrix x;
	row = 0;
	column = 0;
	reoder = nullptr;
	isSolved = false;
	rang = 0;
	method = 1;
}
Slau::Slau(int input_row, int input_column) {
	Matrix a(input_row, input_column);
	Matrix b(input_row, 0);
	Matrix x(input_row, 0);
	row = input_row;
	column = input_column;
	reoder = new int[column];
	for (int i = 0; i < column; i++)
		reoder[i] = i;
	isSolved = false;
	rang = 0;
	method = 1;
	if (input_row != input_column) method = 3;
}
void Slau::changeMethod(int numb) {
	if (row != column)
		method = 3;
	else if ((numb > 0)&&(numb < 4))
		method = numb;
	solve();
}
void Slau::kramer() {
	if (row != column) return; 
	double det = a.determinant();
	if (det == 0) return;
	rang = row;
	Matrix temp = a;
	Matrix result(1, column);
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < column; i++) 
			temp[i][j] = b[i][0];
		result[0][j] = temp.determinant() / det;
		for (int i = 0; i < column; i++)
			temp[i][j] = a[i][j];
	}
	this->x = !result;
	isSolved = true;
}
void Slau::inverseMatrix() {
	if (row != column) return;
	Matrix inverse = ~a;
	Matrix bTemp = !b;
	Matrix x(1, column);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			x[0][j] += inverse[j][i] * bTemp[0][i];
		}
	}
	for (int i = 0; i < column; i++) {
		x[0][i] = std::round(x[0][i]);
	}
	this->x = !x;
	std::cout << x[0][0] << std::endl;
	rang = row;
	isSolved = true;
}
void Slau::jordanGauss() {
	Matrix A = a;
	Matrix B = !b;
	int countOfNullCols = 0;
	for (int i = 0; i < row; i++) {
		if (A[i][i] != 0) {
			for (int k = 0; k < row; k++) {
				if (k == i) continue;
				double d = A[k][i] / A[i][i];
				for (int j = i; j < column; j++) A[k][j] = A[k][j] - d * A[i][j];
				B[0][k] = B[0][k] - d * B[0][i];
			}
			for (int j = i + 1; j < column; j++) A[i][j] /= A[i][i];
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
				swapRow(A, i, k);
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
	this->x = res;
	isSolved = true;
}
void Slau::solve() {
	if (method == 1) kramer();
	else if (method == 2) inverseMatrix();
	else jordanGauss();
}
std::istream& operator >> (std::istream& in, Slau& obj) {
	in >> obj.a;
	in >> obj.b;
	obj.method = 3;
	obj.solve();
	return in;
}
std::ostream& operator << (std::ostream& out, const Slau& obj) {
	out << "Matrix: \n";
	for (int i = 0; i < obj.row; i++) {
		for (int j = 0; j < obj.column; j++)
			out << std::setw(7) << obj.a[i][j];
		out << std::setw(4) << "|" << std::setw(4) << obj.b[i][0] << "\n";
	}
	out << "Result of SLAU: \n";
	if (!obj.isSolved) return out << "System incomplete \n";
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
			}
			out << "\n";
		}
	} else {
		out << "{";
		for (int i = 0; i < obj.column - 1; i++)
			out << obj.x[i][0] << ", "; 
		out << obj.x[obj.column - 1][0] << "}\n";
	}
}