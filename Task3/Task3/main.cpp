//   Ex.4 Postulat Bertrana
#include <iostream>
#include <fstream>
#include "Number.h"

int main(int argc, const char * argv[]) {
    std::fstream fin("input.txt");
    std::ofstream fout("output.txt");
    Number test;
    fin >> test;
    fout << test;
    fout.close();

    std::cout << test.getNumber() << std::endl;
    test.setNumber(15);
    std::cout << test.getNumber() << std::endl;
    std::cout << test.getCount() << std::endl;
    std::cout << test;
    return 0;
}
