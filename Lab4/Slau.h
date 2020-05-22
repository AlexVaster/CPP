#pragma once
#include "Matrix.h"

class Slau : public Matrix {
public:
	Slau();
	Slau(int, int);
	void changeMethod(int);

	friend std::istream& operator >> (std::istream&, Slau&);
	friend std::ostream& operator << (std::ostream&, const Slau&);
private:
	int row;      
	int column;	  
	Matrix a;	  // Matrix coeffs
	Matrix b;	  // Vector
	Matrix x;	  // Result vector
	bool isSolved;// Ñompatibility
	int* reoder;  // Variables in the Gauss Jordan method
	int rang;     
	int method;   // Method of solution
	void kramer();
	void inverseMatrix();
	void jordanGauss();
	void solve();
};