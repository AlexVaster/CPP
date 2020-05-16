#include "Timer.hpp"

Timer::Timer(){
    inputHour = 0;
    inputMin = 0;
    inputSec = 0;
    timerHour = 0;
    timerMin = 0;
    timerSec = 0;
    calculate();
}
Timer::Timer(int hh, int mm, int ss, int timerHH, int timerMM, int timerSS){
    inputHour = hh;
    inputMin = mm;
    inputSec = ss;
    timerHour = timerHH;
    timerMin = timerMM;
    timerSec = timerSS;
    checker();
    calculate();
}
void Timer::setTimerHour(int numb) {
    timerHour = numb;
    checker();
}
void Timer::setTimerMin(int numb) {
    timerMin = numb;
    checker();
}
void Timer::setTimerSec(int numb) {
    timerSec = numb;
    checker();
}
std::istream& operator>>(std::istream& in, Timer& timer) {
    char delim;
    int hh = -1;
    int mm = -1;
    int ss = -1;
    in >> timer.inputHour >> delim >> timer.inputMin >> delim >> timer.inputSec;
    in >> hh >> delim >> mm >> delim >> ss;
    if ((mm == -1)&&(ss == -1)) {
        timer.timerSec = hh;
    } else if (ss == -1) {
        timer.timerSec = mm;
        timer.timerMin = hh;
    } else {
        timer.timerHour = hh;
        timer.timerMin = mm;
        timer.timerSec = ss;
    }
    if ((hh != -1) && (mm != -1) && (ss != -1)) {
        std::cout << timer.timerHour << ":" << timer.timerMin << ":" << timer.timerSec << std::endl;
    } else if ((hh != -1)&&(mm != -1)) {
        std::cout << timer.timerMin << ":" << timer.timerSec << std::endl;
    } else {
        std::cout << timer.timerSec << std::endl;
    }
    timer.calculate();
    return in;
}
std::ostream& operator<<(std::ostream& out, const Timer& timer) {
    if (timer.resultHour < 10) {
        out << "0" << timer.resultHour << ":" ;
    } else {
        out << timer.resultHour << ":" ;
    }
    if (timer.resultMin < 10) {
        out << "0" << timer.resultMin << ":";
    } else {
        out << timer.resultMin << ":";
    }
    if (timer.resultSec < 10) {
        out << "0" << timer.resultSec;
    } else {
        out << timer.resultSec;
    }
    if (timer.resultDay > 0) {
        out << " + " << timer.resultDay << " days";
    }
    out << std::endl;
    timer.checker();
    return out;
}
void Timer::calculate() {
    int allSeconds = ((timerHour + inputHour) * 3600) + ((timerMin + inputMin) * 60) + timerSec + inputSec;
    resultDay = allSeconds / 86400;
    allSeconds %= 86400;
    resultHour = allSeconds / 3600;
    allSeconds %= 3600;
    resultMin = allSeconds / 60;
    allSeconds %= 60;
    resultSec = allSeconds;
}
void Timer::checker() { 
    if ((inputHour < 0) || (inputHour > 23)) inputHour = 0;
    if ((inputMin < 0) || (inputMin > 59)) inputMin = 0;
    if ((inputSec < 0) || (inputSec > 59)) inputSec = 0;
    if (timerHour < 0) timerHour = 0;
    if (timerMin < 0) timerMin = 0;
    if (timerSec < 0) timerSec = 0;
}