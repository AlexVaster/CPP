#include <iostream>
#include "date.h"
#include <stdlib.h>
#include <ctime>

DateTime::DateTime() {
    today();
}
DateTime::DateTime(DateTime& date) {
    setSec(date.getSec());
    setMin(date.getMin());
    setHour(date.getHour());
    setDay(date.getDay());
    setMonth(date.getMonth());
    setYear(date.getYear());
}
DateTime::DateTime(int dd, int MM, int yyyy, int hh, int mm, int ss) {
    DateTime::day = dd;
    DateTime::month = MM;
    DateTime::year = yyyy;
    DateTime::hour = hh;
    DateTime::minute = mm;
    DateTime::second = ss;
    if (!isValid()) {
        today();
    }
}
void DateTime::setSec(int s) {
    if ((s > -1) && (s < 60)) { second = s; }
}
void DateTime::setMin(int m) {
    if ((m > -1) && (m < 60)) { minute = m; }
}
void DateTime::setHour(int h) {
    if ((h > -1) && (h < 24)) { hour = h; }
}
void DateTime::setDay(int d) {
    if ((d > 0) && (d < 32)) { day = d; }
}
void DateTime::setMonth(int m) {
    if ((m > 0) && (m < 13)) { month = m; }
}
void DateTime::setYear(int y) {
    if (y > 0){ year = y; } 
    // 3000-ый год не предел :)
}
void DateTime::print(std::string format) {
    std::cout << toString(format) << std::endl;
}
void DateTime::today() {
    struct tm localtm;
    time_t now = ::time(0);
    localtime_s(&localtm, &now);
    setSec(localtm.tm_sec);
    setMin(localtm.tm_min);
    setHour(localtm.tm_hour);
    setDay(localtm.tm_mday);
    setMonth(localtm.tm_mon + 1);
    setYear(localtm.tm_year + 1900);
}
std::string DateTime::toString(std::string format) {
    int n;
    std::string s;
    n = (int)format.find("dd");
    if (n > -1) {
        s = std::to_string(getDay());
        if (getDay() < 10) {
            s = s.insert(0, "0");
        }
        format.replace(n, 2, s);
    }
    n = (int)format.find("MM");
    if (n > -1) {
        s = std::to_string(getMonth());
        if (getMonth() < 10) {
            s = s.insert(0, "0");
        }
        format.replace(n, 2, s);
    }
    n = (int)format.find("yyyy");
    if (n > -1) {
        s = std::to_string(getYear());
        format.replace(n, 4, s);
    }
    n = (int)format.find("hh");
    if (n > -1) {
        s = std::to_string(getHour());
        if (getHour() < 10) {
            s = s.insert(0, "0");
        }
        format.replace(n, 2, s);
    }
    n = (int)format.find("mm");
    if (n > -1) {
        s = std::to_string(getMin());
        if (getMin() < 10) {
            s = s.insert(0, "0");
        }
        format.replace(n, 2, s);
    }
    n = (int)format.find("ss");
    if (n > -1) {
        s = std::to_string(getSec());
        if (getSec() < 10) {
            s = s.insert(0, "0");
        }
        format.replace(n, 2, s);
    }
    return format;
}
bool DateTime::isValid() {
    return ((isValidDate(day, month, year)) && (isValidTime(hour, minute, second)));
}
bool DateTime::isValidDate(int day, int month, int year) {
    if (((month < 1) || (month > 12)) || (year < 0)) {
        return false;
    }
    if (((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) && ((day < 1) || (day > 31))) {
        return false;
    }
    if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && ((day < 1) || (day > 30))) {
        return false;
    }
    if ((year % 4) == 0) {
        if ((year % 100) != 0) {
            if ((month == 2) && ((day < 1) || (day > 29))) {
                return false;
            }
        }
        else if ((year % 400) == 0) {
            if ((month == 2) && ((day < 1) || (day > 29))) {
                return false;
            }
        }
        else if ((month == 2) && ((day < 1) || (day > 28))) {
            return false;
        }
    }
    else if ((month == 2) && ((day < 1) || (day > 28))) {
        return false;
    }
    return true;
}
bool DateTime::isValidTime(int hour, int minute, int second) {
    return !(((minute < 0) || (minute > 59)) || ((hour < 0) || (hour > 24)) || ((second < 0) || (second > 60)));
}
std::string DateTime::time() {
    return toString("hh:mm:ss");
}
std::string DateTime::date() {
    return toString("dd.MM.yyyy");
}
DateTime DateTime::fromString(std::string s) {
    std::string time = s.substr(0, s.find(" "));
    std::string date = s.substr(s.find(" ")+1, s.length());
    int dd = 0, MM = 0, yyyy = 0, hh = 0, mm = 0, ss = 0;
    if (date.find(':') == 2) {
        std::string temp = time;
        time = date;
        date = temp;
    }
    hh = std::stoi(time.substr(0, 2));
    mm = std::stoi(time.substr(3, 4));
    ss = std::stoi(time.substr(6, 7));
    dd = std::stoi(date.substr(0, 2));
    MM = std::stoi(date.substr(3, 4));
    yyyy = std::stoi(date.substr(6, 9));
    DateTime newDate(dd, MM, yyyy, hh, mm, ss);
    return newDate;
}