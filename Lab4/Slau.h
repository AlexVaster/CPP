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
	int row;      // ���������� ��������� 
	int column;	  // ���������� ����������
	Matrix a;	  // ������� ����.
	Matrix b;	  // ������ ������ �����
	Matrix x;	  // ������ �������
	bool isSolved;// ������� �������������
	int* reoder;  // ������������ ����������, ���������� � ������ �������-������
	int rang;     // ���� ������� �������������
	int method;   // ����� ������� ���� 

	void solve(int numb = 1);
};