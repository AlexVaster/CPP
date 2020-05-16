#include <iostream>
#include "Polynomial.h"

int main() {
    // CONSTRUCTORS
    Polynomial emptyPoly;
    std::cout << "Constructor without parameters: " << emptyPoly;
    Polynomial withOne(3);
    std::cout << "Constructor with one paramenter: " << withOne;
    double coeffs[] = {-4, -7, -22, -1};
	Polynomial notEmptyPoly(coeffs, 4);
    std::cout << "Constructor with parameters: " << notEmptyPoly;
    // OVERLOADED [] AND METHOD at()
	notEmptyPoly.at(0) = 3;
	std::cout << "notEmptyPoly.at(0) = 3"<< std::endl << notEmptyPoly;
	notEmptyPoly[2] = 5;
    std::cout << "notEmptyPoly[2] = 5: " << std::endl << notEmptyPoly << std::endl;
    // METHOD EVALUATE
    double coeffs2[] = {1, 3, 0, 2};
    Polynomial test(coeffs2, 4);
    std::cout << test;
    std::cout << "evaluate for x = 2: " << test.evaluate(2) << std::endl << std::endl;
    // ARITHMETIC OPERATIONS
    double list_a[] = {10, -6, -4, 3};
    Polynomial a(list_a, 4);
    double list_b[] = {-2, 1};
    Polynomial b(list_b, 2);
    std::cout << "a: " << a;
    std::cout << "b: " << b;
    std::cout << std::endl;
    std::cout << "a + b:  " << a + b;
    std::cout << "a - b:  " << a - b;
    std::cout << "a * b:  " << a * b;
    std::cout << "a / b:  " << a / b;
    std::cout << "a % b:  " << a % b;
    std::cout << std::endl;

    Polynomial temp1(a);
    temp1 += b;
    std::cout << "a += b:  " << temp1;

    Polynomial temp2(a);
    temp2 -= b;
    std::cout << "a -= b:  " << temp2;

    Polynomial temp3(a);
    temp3 *= b;
    std::cout << "a *= b:  " << temp3;

    Polynomial temp4(a);
    temp4 /= b;
    std::cout << "a /= b:  " << temp4;

    Polynomial temp5(a);
    temp5 %= b;
    std::cout << "a %= b:  " << temp5;
    std::cout << std::endl;
    
    //IN/OUT
    unsigned int sizea;
    unsigned int sizeb;
    std::cout << "enter your poly size: " << std::endl;
    std::cin >> sizea;
    Polynomial test2(sizea);
    std::cout << "enter your poly of size("<< sizea << "): " << std::endl;
    std::cin >> test2;
    std::cout << "enter your poly size: " << std::endl;
    std::cin >> sizeb;
    Polynomial test3(sizeb);
    std::cout << "enter your poly of size(" << sizeb << "): " << std::endl;
    std::cin >> test3;
    std::cout << test2 << std::endl;
	std::cout << test3 << std::endl << std::endl;
    b = a;
    std::cout << "Copy of a: " << b << std::endl;
    
    std::cout << "Unary operator '-' on object a "<< -a << std::endl;
    std::cout << "Unary opetator '+' on object a " << +a << std::endl;
    double list_a1[] = {1, 0, 1};
    Polynomial a1(list_a1, 3);
    double list_b1[] = {-1, 0, 1};
    Polynomial b1(list_b1, 3);
    std::cout << a1 - b1 << std::endl;
    std::cout << b1 - a1 << std::endl;

    double a_list_test[] = {1, 0, 1};
    Polynomial a_test(a_list_test, 3);
    std::cout << "a = 1x^2 + 1:  " << a_test << std::endl;
    std::cout << "-a = - 1x^2 + 1:  " << -a_test << std::endl;

    double b_list_test[] = {0, 0, 2};
    Polynomial b_test(b_list_test, 3);
    std::cout << "2x^2 + 0x^1 + 0:  " << b_test << std::endl;

    double a_division[] = { 1, 0, 0, 0, -1 };
    double b_division[] = { 1, 0, -1};
    Polynomial a_div(a_division, 5);
    Polynomial b_div(b_division, 3);

    std::cout << "a/b: " << a_div / b_div << std::endl;
    std::cout << "a%b: " << a_div % b_div << std::endl;
	return 0;
}
