#include "number.hpp"
#include <cmath>

Number::Number() {
    this->count = 0;
    this->listOfNumbers = nullptr;
    this->sumOfDigits = nullptr;
    this->maxNumb = 0;
    this->maxNumbIndex = 0;
}
Number::Number(int count) {
    this->count = count;
    this->listOfNumbers = new int[count];
    this->sumOfDigits = new int[count];
    for (int i = 0; i < count; i++) {
        setNumber(i, 0);
        setSum(i);
    }
    maximum();
}
Number::Number(int count, int arr[]) {
    this->count = count;
    this->listOfNumbers = new int[count];
    this->sumOfDigits = new int[count];
    for (int i = 0; i < count; i++) {
        setNumber(i, arr[i]);
        setSum(i);
    }
    maximum();
}
Number::~Number() {
    delete[] listOfNumbers;
    delete[] sumOfDigits;
}
int Number::getCount(){
    return count;
}
int Number::getNumber(int index){
    if ((index >= count) || (index < 0)) {
        return 0;
    }
    return listOfNumbers[index];
}
int Number::getSum(int index){
    if ((index >= count) || (index < 0)) {
        return 0;
    }
    return sumOfDigits[index];
}
void Number::setCount(int number){
    int *tempList = new int[number]; 
    delete[] sumOfDigits;
    this->sumOfDigits = new int[number];
    for (int i = 0; i < number; i++) {
        tempList[i] = listOfNumbers[i];
        setSum(i);
    }
    this->count = number;
    delete[] listOfNumbers;
    this->listOfNumbers = tempList;
    maximum();
}
void Number::setNumber(int index, int number){
    this->listOfNumbers[index] = number;
    maximum();
}
void Number::maximum(){
    int maxSum = getSum(0);
    int index = 0;
    for (int i = 1; i < getCount(); i++) {
        if (maxSum < getSum(i)) {
            maxSum = getSum(i);
            index = i;
        } else if (maxSum == getSum(i)){
            if (getNumber(index) < getNumber(i)) {
                maxSum = getSum(i);
                index = i;
            }
        }
    }
    maxNumbIndex = index;
    maxNumb = getNumber(index);
}

std::istream& operator>>(std::istream &in, Number &number){
    in >> number.count;
    number.listOfNumbers = new int[number.getCount()];
    number.sumOfDigits = new int[number.getCount()];
    for (int i = 0; i < number.getCount(); i++) {
        in >> number.listOfNumbers[i];
        number.setSum(i);
    }
    number.maximum();
    return in;
}
void Number::setSum(int index) {
    int sum = 0;
    int absNum = getNumber(index);
    while (absNum > 0) {
        sum += absNum % 10;
        absNum /= 10;
    }
    this->sumOfDigits[index] = sum;
}


