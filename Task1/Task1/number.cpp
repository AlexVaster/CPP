#include "number.hpp"
#include <iostream>

Number::Number() {
    setNumber(0);
}
Number::Number(int numb) {
    setNumber(numb);
}
void Number::setNumber(int numb) {
    number = numb;
    findChar();
}
void Number::findChar(){
    int sum = 0;
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    if (sum < number) {
        symbol = 'D';
    } else if (sum == number) {
        symbol = 'P';
    } else {
        symbol = 'A';
    }
}
