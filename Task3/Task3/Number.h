#pragma once
#include <iostream>
class Number {
public:
	Number();
	Number(int numb);
	~Number();

	int getNumber() { return number; }
	int getDivisor(int index) const;
	int getCount() { return countOfDivisors; }
	void setNumber(int numb);
	friend std::istream& operator>>(std::istream& in, Number& input);
	friend std::ostream& operator<<(std::ostream& out, const Number& div);
	int simpleNumber(int number);

private:
	int number;            
	int countOfDivisors = 0; 
	int *listOfDivisors;
	void fillDivides();
};