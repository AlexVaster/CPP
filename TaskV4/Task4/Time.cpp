#include "Time.hpp"
#include <ctime>

Time::Time(){
    inputStyle = 1;
    struct tm localtm;
    time_t now = ::time(0);
    localtime_s(&localtm, &now);
    sec =  localtm.tm_sec;
    min = localtm.tm_min;
    hour = localtm.tm_hour;
    convert();
}
Time::Time(int system, int h, int m, int s){
    inputStyle = system;
    if (inputStyle == 1) {
        hour = h;
        min = m;
        sec = s;
    } else if (inputStyle == 2) {
        dec_hour = h;
        dec_min = m;
        dec_sec = s;
    }
    check();
    convert();
}
void Time::setHour(int numb) {
    hour = numb;
    check();
}
void Time::setMinute(int numb) {
    min = numb;
    check();
}
void Time::setSecond(int numb) {
    sec = numb;
    check();
}
void Time::setDecHour(int numb) {
    dec_hour = numb;
    check();
}
void Time::setDecMinute(int numb) {
    dec_min = numb;
    check();
}
void Time::setDecSecond(int numb) {
    dec_sec = numb;
    check();
}
void Time::setInputStyle(int numb) {
    if ((numb > 0)&&(numb < 3)) {
        inputStyle = numb;
    }
}
std::istream& operator>>(std::istream& in, Time& time) {
    char delim;
    in >> time.inputStyle;
    if (time.inputStyle == 1) {
        in >> time.hour;
        in >> delim;
        in >> time.min;
        in >> delim;
        in >> time.sec;
    } else if (time.inputStyle == 2) {
        in >> time.dec_hour;
        in >> delim;
        in >> time.dec_min;
        in >> delim;
        in >> time.dec_sec;
    }
    time.check();
    time.convert();
    return in;
}
std::ostream& operator<<(std::ostream& out, const Time& time) {
    if (time.inputStyle == 1) {
        out << time.dec_hour << ":" ;
        if (time.dec_min < 10) {
            out << "0" << time.dec_min << ":";
        } else {
            out << time.dec_min << ":";
        }
        if (time.dec_sec < 10) {
            out << "0" << time.dec_sec;
        } else {
            out << time.dec_sec;
        }
    } else {
        if (time.hour < 10) {
            out << "0" << time.hour << ":";
        } else {
            out << time.hour << ":" ;
        }
        if (time.min < 10) {
            out << "0" << time.min << ":";
        } else {
            out << time.min << ":";
        }
        if (time.sec < 10) {
            out << "0" << time.sec;
        } else {
            out << time.sec;
        }
    }
    out << std::endl;
    return out;
}
void Time::convert(){
    if (inputStyle == 1) {
        int decSeconds = (hour * 3600 + min * 60 + sec) / 0.864;
        dec_hour = decSeconds / 10000;
        dec_min = (decSeconds / 100) % 100;
        dec_sec = decSeconds % 100;
    } else {
        int nowSeconds = (dec_hour * 10000 + dec_min * 100 + dec_sec) * 0.864;
        hour = nowSeconds / 3600;
        min = (nowSeconds / 60) % 60;
        sec = nowSeconds % 60;
    }
}
void Time::check(){
    if (inputStyle == 1) {
        if ((hour < 0)||(hour > 23)) {
            hour = 0;
        }
        if ((min < 0)||(min > 59)) {
            min = 0;
        }
        if ((sec < 0)||(sec > 59)) {
            sec = 0;
        }
    } else {
        if ((dec_hour < 0)||(dec_hour > 9)) {
            dec_hour = 0;
        }
        if ((dec_min < 0)||(dec_min > 99)) {
            dec_min = 0;
        }
        if ((dec_sec < 0)||(dec_sec > 99)) {
            dec_sec = 0;
        }
    }
}
