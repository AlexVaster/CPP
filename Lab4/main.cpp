#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "Slau.h"

int main() {
	Matrix test;
	std::ifstream fin("input.txt");
	std::ifstream inMatrix("Matrix.txt");
	std::ifstream nonSquare("nonSquareMatrix.txt");
	std::ifstream nonSquare2("nonSquareMatrix2.txt");
	std::ofstream fout("output.txt");
	fin >> test;
	fout << test;
	fout.close();

	int list1[] = {-1, 2, 5, 3, 0, 5, -8, 8, 2};
	int list2[] = {1, 3, 4, 5, 1, -5, 4, 1, 0};
	Matrix a(3, 3, list1);
	Matrix b(3, 3, list2);
	Matrix res;
	bool logic = false;

	std::cout << "(a) " << a << "\n";
	std::cout << "(b) " << b << "\n";

	res = -a;
	std::cout << "Result of '-a' " << res << "\n";

	res = a + b;
	std::cout << "Result of 'a + b' " << res << "\n";

	res = a - b;
	std::cout << "Result of 'a - b' " << res << "\n";

	res = a * b;
	std::cout << "Result of 'a * b' " << res << "\n";

	res = a / b;
	std::cout << "Result of 'a / b' " << res << "\n";

	res = a * 2;
	std::cout << "Result of 'a * 2' " << res << "\n";

	logic = a == a;
	std::cout << "Result of 'a == a' " << logic << "\n";

	logic = a == b;
	std::cout << "Result of 'a == b' " << logic << "\n";

	logic = a != b;
	std::cout << "Result of 'a != b' " << logic << "\n\n";

	res = !a;
	std::cout << "Result of '!a' " << res << "\n";

	res = ~a;
	std::cout << "Result of '~a' " << res << "\n";
	std::cout << "Det of a = " << a.determinant() << "\n\n";

	// operator [][]
	std::cout << "Operator[][]  b[0][1] " << b[0][1] << "\n";
	std::cout << "Operator at b.at(0, 1) " << b.at(0, 1) << "\n\n";

	// subMatrix()
	Matrix sub(3, 3, list2);
	std::cout << "SubMatrix of 3x3 " << 
			     sub << "1 row, 1 column sub" << sub.subMatrix(1, 1) << "2 row, 2 column sub" << 
			     sub.subMatrix(2, 2) << "0 row, 1 column sub" << sub.subMatrix(0,1);
	// setValue()
	b.setValueAt(5, 0, 1);
	std::cout << "setValue(5, 0, 1) " << b;

	// SLAU
	Slau example(3, 3);
	inMatrix >> example;
	std::cout << example;
	// Without solution
	Slau example2(3, 4);
	nonSquare >> example2;
	std::cout << example2;
	// With solution
	Slau example3(3, 4);
	nonSquare2 >> example3;
	std::cout << example3;

	// Manual input from cin
	// input: row column elements

	/*Matrix test123;
	std::cin >> test123;
	std::cout << test123;*/

	return 0;
}