#pragma once
#include <iostream>

class Quad {
public:
    Quad();
    Quad(int numb, int count);
    
    int getInput() const { return inputNumber; }
    int getStage() const { return stage; }
    int getResult() const { return resultNumber; }
    void setInput(int numb);
    void setStage(int numb);

    friend std::istream& operator>>(std::istream& in, Quad& quad);
    friend std::ostream& operator<<(std::ostream& out, const Quad& quad);
private:
    int inputNumber;
    int resultNumber;
    int stage;
    void sumKvadrat();
};
