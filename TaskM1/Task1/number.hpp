#pragma once
#include <iostream>

class Number {
public:
    Number();
    Number(int count);
    Number(int count, int arr[]);
    ~Number();
    
    int getCount();
    int getNumber( int index);
    int getSum( int index);
    int getMaxNumb(){return maxNumb;}
    int getMaxNumbIndex(){return maxNumbIndex;}
    void setCount( int number);
    void setNumber( int index, int number);

    friend std::istream& operator>>(std::istream &in, Number &number);
private:
    int count;
    int maxNumbIndex;
    int maxNumb;
    int *listOfNumbers;
    int *sumOfDigits;
    void maximum();
    void setSum(int index);
};


