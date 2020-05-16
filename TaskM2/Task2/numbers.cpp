#include "numbers.hpp"

Numbers::Numbers() {
    numbers = nullptr;
    size = 0;
    searchForLocals();
}
Numbers::Numbers(int count, int arr[]) {
    size = count;
    numbers = new int[size];
    for (int i = 0; i < size; i++) {
        numbers[i] = arr[i];
    }
    searchForLocals();
}
Numbers::~Numbers() {
    delete[] numbers;
}
int Numbers::getMin(int index) {
    if ((index >= countMins)||(index < 0)) {
        return 0;
    }
    return localMins[index];
}
int Numbers::getMax(int index) {
    if ((index >= countMins) || (index < 0)) {
        return 0;
    }
    return localMaxs[index];
}
void Numbers::setNumber(int index, int number) {
    if ((index < countMins) || (index > -1)) {
        numbers[index] = number;
        searchForLocals();
    }
}
void Numbers::searchForLocals() {
    for (int i = 1; i < size; i++) {
        if ((numbers[i] < numbers[i + 1]) && (numbers[i] < numbers[i - 1])) {
            countMins++;
        }
        else if ((numbers[i] > numbers[i + 1]) && (numbers[i] > numbers[i - 1])) {
            countMaxs++;
        }
    }
    if ((countMaxs > 0) || (countMins > 0)) {
        localMins = new int[countMins];
        localMaxs = new int[countMaxs];
        for (int i = 1, minIndex = 0, maxIndex = 0; i < size; i++) {
            if ((numbers[i] < numbers[i + 1]) && (numbers[i] < numbers[i - 1])) {
                localMins[minIndex] = numbers[i];
                minIndex++;
            }
            else if ((numbers[i] > numbers[i + 1]) && (numbers[i] > numbers[i - 1])) {
                localMaxs[maxIndex] = numbers[i];
                maxIndex++;
            }
        }
    }
}
std::istream& operator>>(std::istream& in, Numbers& number) {
    in >> number.size;
    number.numbers = new int[number.size];
    for (int i = 0; i < number.size; i++) {
        in >> number.numbers[i];
    }
    number.searchForLocals();
    return in;
}