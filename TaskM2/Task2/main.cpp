//  Ex.33 Local extremums
#include <iostream>
#include <fstream>
#include "numbers.hpp"

int main(int argc, const char* argv[]) {
    std::fstream fin("EXTREMUM.IN");
    std::ofstream fout("EXTREMUM.OUT");
    Numbers locals;
    fin >> locals;

    fout << "Min: " << locals.getCountMin() << " " << std::endl;
    fout << "Max: " << locals.getCountMax() << " ";
    std::cout << "first maximum: " << locals.getMax(0) << std::endl;
    fout.close();
    locals.setNumber(2, 7);
    std::cout << "first maximum after set: " << locals.getMax(0) << std::endl;
    return 0;
}