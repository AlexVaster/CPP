//  Ex.10 Izmenit stroky
#include <iostream>
#include <fstream>
#include "words.hpp"

int main() {
    Words letter;
    std::ifstream fin("CAPITAL.IN");
    std::ofstream fout("CAPITAL.OUT");
    fin >> letter;
    fout << letter.getResultString();
    fout.close();

    std::string temp = "Hello, world!";
    Words test(temp);
    std::cout << test.getInputString() << std::endl;
    std::cout << test.getResultString() << std::endl;
    test.setString("hey");
    std::cout << test.getInputString() << std::endl;
    std::cout << test.getResultString() << std::endl;
    return 0;
}
