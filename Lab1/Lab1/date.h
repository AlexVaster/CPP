#pragma once

#include <string>

class DateTime {
private:
    int second, minute, hour, day, month, year;
public:
    DateTime();
    DateTime(DateTime& date);
    DateTime(int sec, int min, int hour, int day, int month, int year);
    int getSec() const { return second; }
    int getMin() const { return minute; }
    int getHour() const { return hour; }
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    void setSec(int s);
    void setMin(int m);
    void setHour(int h);
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    void today();
    void print(std::string format = "dd.MM.yyyy hh:mm:ss");
    std::string toString(std::string format = "dd.MM.yyyy hh:mm:ss");
    bool isValid();
    static bool isValidDate(int day, int month, int year);
    static bool isValidTime(int hour, int minute, int second);
    std::string time();
    std::string date();
    static DateTime fromString(std::string s);
};
