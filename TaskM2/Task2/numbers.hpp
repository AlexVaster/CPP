#pragma once
#include <iostream>

class Numbers {
public:
    Numbers();
    Numbers(int count, int arr[]);
    ~Numbers();

    int getMin(int index);
    int getMax(int index);
    void setNumber(int index, int number);
    int getCountMin() const { return countMins; }
    int getCountMax() const { return countMaxs; }
    friend std::istream& operator>>(std::istream& in, Numbers& number);
private:
    int countMins = 0;
    int countMaxs = 0;
    int size;
    int* numbers;
    int* localMins;
    int* localMaxs;
    void searchForLocals();
};
