#pragma once
#include <string>

class DateTime {
public:
    DateTime();
    DateTime(DateTime&);
    DateTime(int, int, int, int, int, int);
    
    void setTimer(int, int, int);
    void today();
    std::string toString(std::string format = "dd.MM.yyyy hh:mm:ss") const;
    bool isValid();
    static bool isValidDate(int, int, int);
    static bool isValidTime(int, int, int);
    std::string time() const;
    std::string date() const;
    static DateTime fromString(std::string);

    friend std::istream& operator>>(std::istream&, DateTime&);
    friend std::ostream& operator<<(std::ostream&, const DateTime&);
private:
    int second, minute, hour, day, month, year;
    int timerSec, timerMin, timerHour, timerDay, timerMonth, timerYear;
    void calculate();
};
