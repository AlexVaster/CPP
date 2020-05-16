#include "progression.hpp"

Progression::Progression(){
    sizeArr = 0;
    array = nullptr;
    maxArray = nullptr;
    maxCounter = 0;
    stepOfProg = 0;
}
Progression::Progression(int size, int* arr){
    sizeArr = size;
    array = new int[sizeArr];
    for (int i = 0; i < sizeArr; i++) {
        array[i] = arr[i];
    }
    findStep();
}
Progression::~Progression(){
    delete [] array;
    delete [] maxArray;
}
int Progression::getArr(int index) const{
    if ((index >= sizeArr) || (index < 0)) {
        return 0;
    }
    return array[index];
}
int Progression::getMaxArr(int index) const {
    if ((index >= maxCounter) || (index < 0)) {
        return 0;
    }
    return maxArray[index];
}
void Progression::setArr(int size, int *arr){
    if (array != nullptr) {
        delete [] array;
    }
    sizeArr = size;
    array = new int[sizeArr];
    for (int i = 0; i < sizeArr; i++) {
        array[i] = arr[i];
    }
    findStep();
}

std::istream& operator>>(std::istream& in, Progression& prog) {
    in >> prog.sizeArr;
    prog.array = new int[prog.sizeArr];
    for (int i = 0; i < prog.sizeArr; i++) {
        in >> prog.array[i];
    }
    prog.findStep();
    return in;
}
// Вывод массива с последовательностью максимальной длины
std::ostream& operator<<(std::ostream& out, const Progression& prog) {
    if (prog.sizeArr == 0) {
        return out << 0;
    }
    out << "Последовательность: ";
    for (int i = 0; i < prog.sizeArr; i++) {
        out << prog.array[i] << " ";
    }
    out << std::endl << "Максимальная длина: " << prog.maxCounter << " из чисел: ";
    for (int i = 0; i < prog.maxCounter; i++) {
        out << prog.maxArray[i] << " ";
    }
    out << std::endl;
    return out;
}

void Progression::findStep(){
    maxCounter = 0;
    int counter = 0;
    
    if (sizeArr == 2) {
        maxCounter = 2;
        maxArray = new int[maxCounter];
        for (int i = 0; i < maxCounter; i++) {
            maxArray[i] = array[i];
        }
    } else {
        stepOfProg = getArr(1)-getArr(0);
        counter = 2;
        int startIndex = 0;
        int tempIndex = 0;
        for (int i = 2; i < sizeArr; i++) { 
            if (stepOfProg == getArr(i) - getArr(i - 1)) {
                counter++;
                if (maxCounter <= counter) maxCounter = counter;
            } else {
                stepOfProg = getArr(i) - getArr(i - 1);
                counter = 2;
                tempIndex = i - 1;
                if (maxCounter <= counter) maxCounter = counter;
            }
            if (i == sizeArr - 1) {
                if ((i - tempIndex) > (tempIndex - startIndex)) {
                    startIndex = tempIndex;
                }
            }
        }
        maxArray = new int[maxCounter];
        for (int i = startIndex, j = 0; i < startIndex + maxCounter; i++, j++) {
            maxArray[j] = array[i];
        }
    }
}
