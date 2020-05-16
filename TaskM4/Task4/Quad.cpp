#include "Quad.hpp"

Quad::Quad() {
    inputNumber = 0;
    stage = 0;
    quadArr = nullptr;
    resultNumber = 0;
}
Quad::Quad(int numb, int count) {
    inputNumber = numb;
    stage = count;
    sumKvadrat();
}
int Quad::getQuadArr(int index) const {
    if ((index < 0)||(index >= stage)) {
        return 0;
    }
    return quadArr[index];
}
void Quad::setInput(int numb) {
    if (numb > 0) {
        inputNumber = numb;
        sumKvadrat();
    }
}
void Quad::setStage(int numb) {
    if (numb >= 0) {
        stage = numb;
        sumKvadrat();
    }
}
std::istream& operator>>(std::istream& in, Quad& quad) {
    in >> quad.inputNumber;
    in >> quad.stage;
    quad.sumKvadrat();
    return in;
}
std::ostream& operator<<(std::ostream& out, const Quad& quad) {
    out << quad.inputNumber << " in " << quad.stage << " stages: " << quad.resultNumber;
    return out;
}
void Quad::sumKvadrat () {
    int sum;
    int number = inputNumber;
    quadArr = new int[stage];
    for (int i = 0; i < stage; i++) {
        sum = 0;
        while (number > 0) {
            if (number < 10) {
                sum += number * number;
            } else {
                sum += (number % 10) * (number % 10);
            }
            number /= 10;
        }
        quadArr[i] = sum;
        number = sum;
    }
    resultNumber = quadArr[stage - 1];
}
