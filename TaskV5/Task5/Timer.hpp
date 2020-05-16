#pragma once
#include <iostream>

class Timer {
public:
    Timer();
    Timer(int hh, int mm, int ss, int timerHH = 0, int timerMM = 0, int timerSS = 0);
    int getInputHour() const { return inputHour; }
    int getInputMin() const { return inputMin; }
    int getInputSec() const { return inputSec; }
    int getTimerHour() const { return timerHour; }
    int getTimerMin() const { return timerMin; }
    int getTimerSec() const { return timerSec; }
    int getResultHour() const { return resultHour; }
    int getResultMin() const { return resultMin; }
    int getResultSec() const { return resultSec; }
    int getResultDay() const { return resultDay; }
    
    void setTimerHour(int hour);
    void setTimerMin(int min);
    void setTimerSec(int sec);
    
    friend std::istream& operator>>(std::istream& in, Timer& timer);
    friend std::ostream& operator<<(std::ostream& out, const Timer& timer);
private:
    int inputHour;
    int inputMin;
    int inputSec;
    
    int timerHour;
    int timerMin;
    int timerSec;
    
    int resultHour;
    int resultMin;
    int resultSec;
    int resultDay;
    
    void calculate();
    void checker();
};
