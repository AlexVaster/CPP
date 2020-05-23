//Ex. 68 Таймер
#include <iostream>
#include <fstream>
#include "date.h"
int main(int argc, const char * argv[]) {
    std::ifstream fin("input.txt");
    DateTime test;
    fin >> test;
    std::cout << test;
    test.setTimer(1, 0, 1);
    std::cout << test;
    return 0;
}
