#pragma once
#include <iostream>

class Time {
public:
    Time();
    Time(int system, int h, int m, int s);
    
    int getHour() const { return hour; }
    int getMinute() const { return min; }
    int getSecond() const { return sec; }
    int getDecHour() const { return dec_hour; }
    int getDecMinute() const { return dec_min; }
    int getDecSecond() const { return dec_sec; }
    
    void setHour(int numb);
    void setMinute(int numb);
    void setSecond(int numb);
    void setDecHour(int numb);
    void setDecMinute(int numb);
    void setDecSecond(int numb);
    
    void setInputStyle(int numb);
    friend std::istream& operator>>(std::istream& in, Time& time);
    friend std::ostream& operator<<(std::ostream& out, const Time& time);
private:
    int hour;
    int min;
    int sec;
    int dec_hour;
    int dec_min;
    int dec_sec;
    int inputStyle;
    void convert();
    void check();
};

