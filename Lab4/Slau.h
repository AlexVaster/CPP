#pragma once
#include "Matrix.h"

class Slau : public Matrix {
public:
	Slau(int, int);
	void solve();
	void kramer();
	void inverseMatrix();
	void jordanGauss();

	friend std::ostream& operator << (std::ostream&, Slau&);
	friend std::istream& operator >> (std::istream&, Slau&);
private:
	int row;      // Количество уравнений 
	int column;	  // Количество переменных
	Matrix a;	  // Матрица коэф.
	Matrix b;	  // Вектор правой части
	Matrix x;	  // Вектор решений
	bool isSolved;// Признак совместимости
	int* reoder;  // Перестановка переменных, полученная в методе Жордана-Гаусса
	int rang;     // Ранг матрицы коэффициентов
};