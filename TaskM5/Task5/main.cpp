//  Ex.60 Progressiya

#include <iostream>
#include <fstream>
#include "progression.hpp"

int main(int argc, const char * argv[]) {
    Progression obj1;
    std::fstream fin("input.txt");
    std::ofstream fout("output.txt");
    fin >> obj1;
    fout << obj1;
    fout.close();
 
    return 0;
}
