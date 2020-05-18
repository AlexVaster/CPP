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
	int row;      // ���������� ��������� 
	int column;	  // ���������� ����������
	Matrix a;	  // ������� ����.
	Matrix b;	  // ������ ������ �����
	Matrix x;	  // ������ �������
	bool isSolved;// ������� �������������
	int* reoder;  // ������������ ����������, ���������� � ������ �������-������
	int rang;     // ���� ������� �������������
};