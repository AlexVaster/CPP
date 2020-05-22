#pragma once
#include "Matrix.h"

class Slau : public Matrix {
public:
	Slau();
	Slau(int, int);
	void changeMethod(int);
	void kramer();
	void inverseMatrix();
	void jordanGauss();

	friend std::istream& operator >> (std::istream&, Slau&);
	friend std::ostream& operator << (std::ostream&, const Slau&);
private:
	int row;      // Количество уравнений 
	int column;	  // Количество переменных
	Matrix a;	  // Матрица коэф.
	Matrix b;	  // Вектор правой части
	Matrix x;	  // Вектор решений
	bool isSolved;// Признак совместимости
	int* reoder;  // Перестановка переменных, полученная в методе Жордана-Гаусса
	int rang;     // Ранг матрицы коэффициентов
	int method;   // Метод решения СЛАУ 

	void solve(int numb = 1);
};