#pragma once
#include <string>
#include <iostream>

class Words {
public:
    Words();
    Words(std::string s);
    std::string getInputString() { return inputRow; }
    std::string getResultString() { return resultRow; }
    void setString(std::string temp);
    friend std::istream& operator>>(std::istream &in, Words &row);
private:
    std::string inputRow;
    std::string resultRow;
    void toUpperString();
};


