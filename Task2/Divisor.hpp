#pragma once
#include <iostream>

class Divisor{
public:
    Divisor();
    Divisor(int inputNumber);
    ~Divisor();
    
    int getNumber() const { return number; }
    int getDivider(int index) const;
    int getCount() const { return counter; }
    void setNumber(int numb);
    friend std::istream& operator>>(std::istream &in, Divisor &input);
    friend std::ostream& operator<<(std::ostream& out, const Divisor& div);
    
private:
    int number;
    int counter;
    int* dividers;
    void calcCount();
};

