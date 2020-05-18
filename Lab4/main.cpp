#include <iostream>
#include <fstream>
#include "Matrix.h"

int main() {
	/*Matrix test1;
	test1.inputMatrix();
	std::cout << test1 << std::endl;*/
	Matrix test2;
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	fin >> test2;
	fout << test2;

	int list1[] = {-1, 2, 5, 3, 0, 5, -8, 8, 2};
	int list2[] = {1, 3, 4, 5, 1, -5, 4, 1, 0};
	Matrix obj1(3, 3, list1);
	Matrix obj2(3, 3, list2);
	Matrix res;
	std::cout << "(a) " << obj1 << std::endl;
	std::cout << "(b) " << obj2 << std::endl;
	res = -obj1;
	std::cout << "Result of '-a' " << res << std::endl;
	res = obj1 + obj2;
	std::cout << "Result of 'a+b' " << res << std::endl;
	res = obj1 - obj2;
	std::cout << "Result of 'a-b' " << res << std::endl;
	res = obj1 * obj2;
	std::cout << "Result of 'a*b' " << res << std::endl;
	res = obj1 * 2;
	std::cout << "Result of 'a* 2'" << res << std::endl;
	res = !obj1;
	std::cout << "Result of '!a' " << res << std::endl;
	res = ~obj1;
	std::cout << "Result of '~a' " << res << std::endl;
	std::cout << "Det of a = " << obj1.determinant() << std::endl << std::endl;
	std::cout << obj2[0][1] << std::endl;
	// subMatrix()
	Matrix sub(3, 3, list2);
	std::cout << "SubMatrix of 3x3 " << 
			     sub << "1 row, 1 column sub" << sub.subMatrix(1, 1) << "2 row, 2 column sub" << 
			     sub.subMatrix(2, 2) << "0 row, 1 column sub" << sub.subMatrix(0,1);
	return 0;
}