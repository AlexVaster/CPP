//Ex.13  √де-то недостаток, а где-то Ц избытокЕ 
#include <iostream>
#include <fstream>
#include "number.hpp"

int main(int argc, const char* argv[]) {
    int size, numb;
    std::ifstream fin("DPA.IN");
    std::fstream fout("DPA.OUT", std::ios::out | std::ios::trunc);
    fin >> size;

    Number* testArr = new Number[size];
    for (int i = 0; i < size; i++) {
        fin >> numb;
        testArr[i].setNumber(numb);
    }
    for (int i = 0; i < size; i++) {
        fout << testArr[i].getSymbol();
    }

    fout.close();
    return 0;
}
