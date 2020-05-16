//  Ex.60 Progressiya

#include <iostream>
#include <fstream>
#include "progression.hpp"

int main(int argc, const char * argv[]) {
    Progression obj1;
    std::fstream fin("/Users/alexvaster/Desktop/Nya/Proga/Task_4(60)/Task_4(60)/input.txt");
    std::ofstream fout("/Users/alexvaster/Desktop/Nya/Proga/Task_4(60)/Task_4(60)/output.txt");
    fin >> obj1;
    fout << obj1.getMaxCounter();
    fout.close();
    std::cout << obj1 << std::endl;
    
    
    
    return 0;
}
