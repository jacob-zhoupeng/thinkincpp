//: C09:Cpptime.h
// A simple time class

#ifndef CPPTIME_H_INCLUDED
#define CPPTIME_H_INCLUDED

#include <ctime>
#include <cstring>

class Time {
public:
    Time() {
        mark();
    }
    void mark() {
        lflag = aflag = 0;
        time(&t);
    }
    const char *ascii() {
        updateAscii();
        return Ascii;
    }
    // Difference in seconds:
    int delta(Time *dt) const {
        return difftime(t, dt->t);
    }
    int DaylightSavings() {
        updateLocal();
        return local.tm_isdst;
    }
    int DayOfYear() { // Since January 1
        updateLocal();
        return local.tm_yday;
    }
    int DayOfWeek() { // Since Sunday
        updateLocal();
        return local.tm_wday;
    }
    int Since1900() { // Years since 1900
        updateLocal();
        return local.tm_year;
    }
    int Month() { // Since January
        updateLocal();
        return local.tm_mon;
    }
    int DayOfMonth() {
        updateLocal();
        return local.tm_mday;
    }
    int Hour() { // Since midight, 24-hour clock
        updateLocal();
        return local.tm_hour;
    }
    int Minute() {
        updateLocal();
        return local.tm_min;
    }
    int Second() {
        updateLocal();
        return local.tm_sec;
    }
private:
    time_t t;
    tm local;
    char Ascii[26];
    unsigned char lflag, aflag;

    void updateLocal() {
        if (!lflag) {
            local = *localtime(&t); // 结构体复制拷贝
            lflag++;
        }
    }

    void updateAscii() {
        if (!aflag) {
            updateLocal();
            strcpy(Ascii, asctime(&local));
            aflag++;
        }
    }
};

#endif // CPPTIME_H_INCLUDED
