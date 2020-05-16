#include <iostream>
#include "date.h"
#include <fstream>
using namespace std;

int main(int argc, const char* argv[]) {
    DateTime date1(-1, 2, 3, 4, 5, 6);
    DateTime date2(date1);
    date1.print();
    cout << date2.getDay() << " .getDay"<< endl;
    cout << date2.toString("dd/yyyy/MM hh:mm:ss") << " .toString"<< endl;
    cout << date2.time() << " .time" << endl;                        
    cout << date2.date() << " .date" << endl;                        
    date2 = DateTime::fromString("23.01.2000 10:20:30");
    date2.print();
    date2 = DateTime::fromString("13.01.1990 23:01:14");
    date2.print();
    cout << date2.toString("yyyy.MM.dd hh:mm:ss") << " .toString" << endl;
    cout << date1.isValid() << " .isValid" << endl;                     
    cout << DateTime::isValidTime(28, 23, 35) << " .isValidTime(28, 23, 35)" << endl;  
    cout << DateTime::isValidDate(13, 13, 2000) << " .isValidDate(13, 13, 2000)"<< endl;
    cout << DateTime::isValidDate(2, 9, 1990) << " .isValidDate(2, 9, 1990)" << endl;  
    ofstream fout;
    fout.open("output.txt", ios::trunc);
    fout << date2.date() << " " << date2.time() << '\n' << date2.toString("yyyy/dd/MM hh:mm:ss");
    cout << date2.getDay() << endl;
    date2.setDay(-25);
    cout << date2.getDay() << " .setDay(-25)" << endl;
    date2.setDay(17); 
    cout << date2.getDay() << " .setDay(17)" << endl;
    DateTime date3(1,1,1,20,13,2000);                       // При вводе неверного числа в конструктор вызывается метод присвоения текущей даты
    date3.print();
    DateTime date4;
    date4 = DateTime::fromString("12:45:15 12/12/2000");    // Ввод сначала времени
    date4.print();
    DateTime date5;
    date5 = DateTime::fromString("02.05.2003 10:31:21");    // Ввод даты, а после - времени
    date5.print();
    return 0;
}
