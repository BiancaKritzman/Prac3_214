#ifndef NOTICE_H
#define NOTICE_H

#include <string>

struct Notice {
    enum class Type { OPEN, CLOSE, SCHEDULE_CHANGE, CAPACITY_ALERT,
                       WEATHER_ALERT, PAUSE, RESUME, EVACUATE };

    Type type;
    std::string message;
    int currentCapacity = 0;   //for CAPACITY_ALERT
    int threshold = 0;         //for CAPACITY_ALERT

    Notice(Type t, std::string msg, int capacity = 0, int thresh = 0)
        : type(t), message(std::move(msg)), currentCapacity(capacity), threshold(thresh) {}
};

#endif