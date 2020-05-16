//Ex. 68
#include <iostream>
#include <fstream>
#include "Timer.hpp"

int main(int argc, const char * argv[]) {
    Timer obj1;
    std::fstream fin("input.txt");
    std::ofstream fout("output.txt");
    fin >> obj1;
    fout << obj1;
    return 0;
}
