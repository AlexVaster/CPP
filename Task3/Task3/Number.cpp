#include "Number.h"

Number::Number(){
    number = 0;
    listOfDivisors = nullptr;
}
Number::Number(int numb) {
    number = numb;
    fillDivides();
}
Number::~Number() {
    delete [] listOfDivisors;
}
int Number::getDivisor(int index) const {
    if ((index >= countOfDivisors) || (index < 0)) {
        return 0;
    }
    return listOfDivisors[index];
}
void Number::setNumber(int numb) {
    number = numb;
    fillDivides();
}
std::istream& operator>>(std::istream& in, Number& input) {
    in >> input.number;
    input.fillDivides();
    return in;
}
std::ostream& operator<<(std::ostream& out, const Number& div) {
    if (div.countOfDivisors == 0) {
        return out << 0;
    }
    for (int i = 0; i < div.countOfDivisors; i++) {
        out << div.getDivisor(i) << " ";
        if ((i % 10 == 0) && (i != 0)) out << std::endl;
    }
    out << std::endl;
    return out;
}
int Number::simpleNumber(int number) {
    int countOfDivides = 0;
    for (int i = 2; i <= number; i++) {
        if (number % i == 0) {
            countOfDivides++;
        }
    }
    if (countOfDivides == 1) return countOfDivides;
    else return 0;
}

void Number::fillDivides() {
    countOfDivisors = 0;
    for (int i = number + 1; i < number * 2; i++) {
        if (simpleNumber(i) > 0) {
            countOfDivisors++;
        }
    }
    listOfDivisors = new int[countOfDivisors];
    for (int i = number + 1, j = 0; i < number * 2; i++) {
        if (simpleNumber(i) > 0) {
            listOfDivisors[j] = i;
            j++;
        }
    }
}