#pragma once
#include <string>

class Number{
public:
    Number();
    Number(int numb);

    int getNumber() const { return number; }
    char getSymbol() const { return symbol; }
    void setNumber(int numb); 

private:
    int number;
    char symbol;
    void findChar();
};

