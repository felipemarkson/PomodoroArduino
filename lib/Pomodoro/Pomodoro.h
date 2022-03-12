#ifndef POMODORO_LIGHS_H
#define POMODORO_LIGHS_H
#include "_PomodoroOut.h"

namespace Pomodoro
{
    struct Timer
    {
    public:
        Timer(int sleepping, int waiting, int working, void (*timeFunc)(unsigned int));
        void reset();
        void setUp(unsigned int time_sleep, unsigned int time_work);
        void goingResting(unsigned int time);
        void goingWorking(unsigned int time);
        bool getHasWorked();
        bool getIsWaiting();
        void change();

    private:
        void goingWaiting();
        void turnOff();
        _PomodoroOut::Out ligthRest;
        _PomodoroOut::Out ligthWait;
        _PomodoroOut::Out ligthWork;
        void (*lightTimeFunc)(unsigned int);
        bool hasWorked;
        bool isWaiting;
        unsigned int time_rest;
        unsigned int time_work;
    };

}

#endif