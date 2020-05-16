#include "Divisor.hpp"

Divisor::Divisor(){
    number = 0;
    counter = 0;
    calcCount();
}
Divisor::Divisor(int inputNumber){
    number = inputNumber;
    calcCount();
}
Divisor::~Divisor() {
    delete [] dividers;
}
int Divisor::getDivider(int index) const {
    if ((index >= counter) || (index < 0)) {
        return 0;
    }
    return dividers[index];
}
void Divisor::setNumber(int numb) {
    number = numb;
    calcCount();
}
std::istream& operator>>(std::istream &in, Divisor &input){
    in >> input.number;
    input.calcCount();
    return in;
}
std::ostream& operator<<(std::ostream& out, const Divisor& div) {
    if (div.counter == 0) {
        return out << 0;
    }
    for (int i = 0; i < div.counter; i++) {
        out << div.getDivider(i) << " ";
    }
    out << std::endl;
    return out;
}
void Divisor::calcCount(){
    counter = 0;
    delete [] dividers;
    for (int M = number / 2; M > 1; M--) {
        if (number % M == 0){
            counter ++;
        }
    }
    dividers = new int[counter];
    for (int i = 0, M = number / 2; M > 1; M--) {
        if (number % M == 0) {
            dividers[i] = number / M;
            i++;
        }
    }
}
