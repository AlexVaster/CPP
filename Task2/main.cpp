//  Ex.41 Netrivialnie deliteli
#include <iostream>
#include <fstream>
#include "Divisor.hpp"

int main(int argc, const char * argv[]) {
    std::ifstream fin("DIVIDORS.IN");
    std::ofstream fout("DIVIDORS.OUT");
    Divisor test;
    fin >> test;
    fout << test.getCount();
    fout.close();
    std::cout << test.getDivider(0) << std::endl;
    std::cout << test;
    test.setNumber(3);
    std::cout << test.getNumber() << std::endl;
    std::cout << test;
    return 0;
}
