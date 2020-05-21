//  Ex. 23 Метрическое время
#include <iostream>
#include "Time.hpp"
#include <fstream>

int main () {
    std::fstream fin("input.txt");
    std::ofstream fout("output.txt");
    int rows;
    fin >> rows;
    Time* listOfTimes = new Time[rows];
    for (int i = 0; i < rows; i++) {
        Time temp;
        fin >> temp;
        std::cout << temp;
        listOfTimes[i] = temp;
        fout << listOfTimes[i];
    }
    fout.close();
    
    // empty constructor
    Time obj1;
    std::cout << "Decimal: " << obj1;
    // change output style
    obj1.setInputStyle(2);
    std::cout << "Normal: " << obj1;
    // method check()
    Time obj2(1, 24, 0, 0);
    obj2.setInputStyle(2);
    std::cout << obj2;
    // wrong numbers into 0
    Time wrong(1, 45, 231, 325);
    std::cout << "Wrong numbers: " << wrong;
    return 0;
}
