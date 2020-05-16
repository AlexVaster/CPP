#include "words.hpp"

Words::Words(){
    inputRow = "";
    resultRow = "";
}
Words::Words(std::string s){
    inputRow = s;
    toUpperString();
}
void Words::setString(std::string temp){
    inputRow = temp;
    toUpperString();
}
void Words::toUpperString(){
    resultRow = inputRow;
    for (int i = 0; i < inputRow.length(); i++) {
        if (i == 0) {
            resultRow[i] = toupper(inputRow[i]);
        } else {
            if (isspace(inputRow[i-1])) {
                resultRow[i] = toupper(inputRow[i]);
            }
        }
    }
}
std::istream& operator>>(std::istream &in, Words &row){
    getline(in, row.inputRow);
    row.toUpperString();
    return in;
}
