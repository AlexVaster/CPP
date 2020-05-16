#pragma once
#include <iostream>

class Progression {
public:
    Progression();
    Progression(int size, int* arr);
    ~Progression();
    
    int getArr(int index) const;
    int getMaxArr(int index) const;
    void setArr(int size, int* arr);
    int getMaxCounter(){ return maxCounter; }
    friend std::istream& operator>>(std::istream& in, Progression& prog);
    friend std::ostream& operator<<(std::ostream& out, const Progression& prog);
private:
    int* array;
    int sizeArr;
    int* maxArray;
    int maxCounter;
    int stepOfProg;
    void findStep();
};
