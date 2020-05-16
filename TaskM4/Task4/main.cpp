//  Ex.17 Квадраты цифр числа

#include <iostream>
#include <fstream>
#include "Quad.hpp"

int main(int argc, const char * argv[]) {
    Quad obj1;
    std::ifstream fin("/Users/alexvaster/Desktop/Nya/Proga/Task_5(17)/Task_5(17)/QUAD.IN");
    std::ofstream fout("/Users/alexvaster/Desktop/Nya/Proga/Task_5(17)/Task_5(17)/QUAD.OUT");
    fin >> obj1;
    fout << obj1;
    fout.close();
    
    Quad test(5321, 7);
    std::cout << test << std::endl;
    return 0;
}
