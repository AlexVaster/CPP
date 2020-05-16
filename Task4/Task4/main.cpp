//  Ex. 23
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
    Time obj2(1, 26, 24, 145);
    obj2.setInputStyle(2);
    std::cout << "Wrong hour: " << obj2;
    return 0;
}
