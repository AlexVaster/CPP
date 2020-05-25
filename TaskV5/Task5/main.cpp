//Ex. 68 Таймер
#include <iostream>
#include <fstream>
#include "date.h"
int main(int argc, const char * argv[]) {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    DateTime test;
    fin >> test;
    std::cout << "Input from file: " << test << "\n";
    test.setTimer(1, 0, 1);
    std::cout << "Set timer 1 hour, 1 minute interval: " << test << "\n";
    fout << test;
    fout.close();

    DateTime test2;
    std::cout << "Empty DateTime object: " << test2 << "\n";
    test2.setTimer(24, 0, 0);
    std::cout << "Set timer 24 hour interval: " << test2 << "\n";
    return 0;
}
