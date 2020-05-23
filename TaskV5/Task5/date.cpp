#include <iostream>
#include "date.h"
#include <ctime>

DateTime::DateTime() {
    today();
    timerSec = 0;
    timerMin = 0;
    timerHour = 0;
    timerDay = 0;
    timerMonth = 0;
    timerYear = 0;
}
DateTime::DateTime(DateTime& date) {
    second = date.second;
    minute = date.minute;
    hour = date.hour;
    day = date.day;
    month = date.month;
    year = date.year;
    timerSec = 0;
    timerMin = 0;
    timerHour = 0;
    timerDay = 0;
    timerMonth = 0;
    timerYear = 0;
}
DateTime::DateTime(int dd, int MM, int yyyy, int hh, int mm, int ss) {
    DateTime::day = dd;
    DateTime::month = MM;
    DateTime::year = yyyy;
    DateTime::hour = hh;
    DateTime::minute = mm;
    DateTime::second = ss;
    timerSec = 0;
    timerMin = 0;
    timerHour = 0;
    timerDay = 0;
    timerMonth = 0;
    timerYear = 0;
    if (!isValid()) {
        today();
    }
}
void DateTime::setTimer(int h, int m, int s) {
    if (h > 0) timerHour = h;
    else timerHour = 0;
    if (m > 0) timerMin = m;
    else timerMin = 0;
    if (s > 0) timerSec = s;
    else timerSec = 0;
    calculate();
}
void DateTime::today() {
    struct tm localtm;
    time_t now = ::time(0);
    localtime_s(&localtm, &now);
    second = localtm.tm_sec;
    minute = localtm.tm_min;
    hour = localtm.tm_hour;
    day = localtm.tm_mday;
    month = localtm.tm_mon + 1;
    year = localtm.tm_year + 1900;
}
std::string DateTime::toString(std::string format) const {
    int n;
    std::string s;
    n = (int)format.find("dd");
    if (n > -1) {
        s = std::to_string(day);
        if (day < 10) {
            s = s.insert(0, "0");
        }
        format.replace(n, 2, s);
    }
    n = (int)format.find("MM");
    if (n > -1) {
        s = std::to_string(month);
        if (month < 10) {
            s = s.insert(0, "0");
        }
        format.replace(n, 2, s);
    }
    n = (int)format.find("yyyy");
    if (n > -1) {
        s = std::to_string(year);
        format.replace(n, 4, s);
    }
    n = (int)format.find("hh");
    if (n > -1) {
        s = std::to_string(hour);
        if (hour < 10) {
            s = s.insert(0, "0");
        }
        format.replace(n, 2, s);
    }
    n = (int)format.find("mm");
    if (n > -1) {
        s = std::to_string(minute);
        if (minute < 10) {
            s = s.insert(0, "0");
        }
        format.replace(n, 2, s);
    }
    n = (int)format.find("ss");
    if (n > -1) {
        s = std::to_string(second);
        if (second < 10) {
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
std::string DateTime::time() const {
    return toString("hh:mm:ss");
}
std::string DateTime::date() const {
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
std::istream& operator>>(std::istream& in, DateTime& timer) {
    char delim;
    int hh = -1;
    int mm = -1;
    int ss = -1;
    in >> hh >> delim >> mm >> delim >> ss;
    if ((mm == -1) && (ss == -1)) {
        if (hh > 0) timer.timerSec = hh;
        else timer.timerSec = 0;
    }
    else if (ss == -1) {
        if (hh > 0) timer.timerMin = hh;
        else timer.timerMin = 0;
        if (mm > 0) timer.timerSec = mm;
        else timer.timerSec = 0;
    }
    else {
        if (hh > 0) timer.timerHour = hh;
        else timer.timerHour = 0;
        if (mm > 0) timer.timerMin = mm;
        else timer.timerMin = 0;
        if (ss > 0) timer.timerSec = ss;
        else timer.timerSec = 0;
    }
    timer.calculate();
    return in;
}
std::ostream& operator<<(std::ostream& out, const DateTime& timer) {
    if (timer.timerHour < 10) out << "0" << timer.timerHour << ":";
    else out << timer.timerHour << ":";
    if (timer.timerMin < 10) out << "0" << timer.timerMin << ":";
    else out << timer.timerMin << ":";
    if (timer.timerSec < 10) out << "0" << timer.timerSec;
    else out << timer.timerSec;
    out << "   ";
    if (timer.timerDay < 10) out << "0" << timer.timerDay << ".";
    else out << timer.timerDay << ".";
    if (timer.timerMonth < 10) out << "0" << timer.timerMonth << ".";
    else out << timer.timerMonth << ".";
    out << timer.timerYear << "\n";
    return out;
}
void DateTime::calculate() {
    int temp = 0;
    long allSeconds = (day * 86400) + ((timerHour + hour) * 3600) 
        + ((timerMin + minute) * 60) + timerSec + second;
    if ((allSeconds / 86400) > day) {
        timerDay = allSeconds / 86400;
        if (timerDay > 30) {
            temp = timerDay / 30;
            timerMonth = month + temp;
            timerDay -= 30 * temp;
            if (timerMonth > 12) {
                temp = timerYear / 12;
                timerYear = year + temp;
                timerMonth -= 12 * temp;
            }
            else {
                timerYear = year;
            }
        }
        else {
            timerMonth = month;
            timerYear = year;
        }
    }
    else {
        timerDay = day;
        timerMonth = month;
        timerYear = year;
    }
    allSeconds %= 86400;
    timerHour = allSeconds / 3600;
    allSeconds %= 3600;
    timerMin = allSeconds / 60;
    allSeconds %= 60;
    timerSec = allSeconds;
}