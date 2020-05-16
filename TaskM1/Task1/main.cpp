//Ex. 31 Наибольшая сумма цифр
#include <iostream>
#include <fstream>
#include "number.hpp"

int main(int argc, const char * argv[]) {
    int list_1[] = { 4, 33, 61, 2, 423, 3 };
    Number test1;
    Number test2(4);
    Number test3(6, list_1);
    std::cout << test1.getCount() << std::endl;
    std::cout << test2.getCount() << std::endl;
    std::cout << test3.getCount() << std::endl;
    std::cout << test3.getNumber(3) << std::endl;

    std::fstream fin("SUMDIGIT.IN");
    fin >> test1;
    std::cout << test1.getCount() << std::endl;
    std::cout << test1.getMaxNumb() << std::endl;
    std::ofstream fout("SUMDIGIT.OUT");
    std::cout << "Number: " << test1.getMaxNumb() << " with sum: " << test1.getSum(test1.getMaxNumbIndex()) << std::endl;
    fout << test1.getMaxNumb();
    fout.close();
    std::cout << "Number: " << test2.getMaxNumb() << " with sum: " << test2.getSum(test2.getMaxNumbIndex()) << std::endl;
    std::cout << "Number: " << test3.getMaxNumb() << " with sum: " << test3.getSum(test3.getMaxNumbIndex()) << std::endl;
    test3.setCount(4);
    std::cout << test3.getNumber(0) << " " << test3.getNumber(1) << " " << test3.getNumber(2) << " " << test3.getNumber(241) << std::endl;
    std::cout << test3.getMaxNumb() << " " << test3.getSum(test3.getMaxNumbIndex()) << std::endl;
    return 0;
}
