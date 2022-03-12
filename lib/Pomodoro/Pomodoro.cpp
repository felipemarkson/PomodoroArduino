#include <Arduino.h>
#include "_PomodoroOut.h"
#include "Pomodoro.h"

namespace Pomodoro
{
    using namespace _PomodoroOut;
    Timer::Timer(int rest_pin, int wait_pin, int work_pin, void (*timeFunc)(size_t))
    {
        ligthRest = Out::create(rest_pin);
        ligthWait = Out::create(wait_pin);
        ligthWork = Out::create(work_pin);
        lightTimeFunc = timeFunc;
        hasWorked = false;
        isWaiting = false;
    };
    void Timer::reset()
    {
        hasWorked = false;
        turnOff();
        goingWaiting();
    };
    void Timer::setUp(unsigned int time_rest, unsigned int time_work)
    {
        Timer::time_rest = time_rest;
        Timer::time_work = time_work;
        ligthRest.setUp();
        ligthWait.setUp();
        ligthWork.setUp();
        delay(15);
        goingWaiting();
        delay(15);
    };

    void Timer::goingResting(unsigned int time)
    {
        turnOff();
        ligthRest.turnOn();
        isWaiting = false;
        lightTimeFunc(time); // resting
        hasWorked = false;
        goingWaiting();
    }
    void Timer::goingWorking(unsigned int time)
    {
        turnOff();
        ligthWork.turnOn();
        isWaiting = false;
        lightTimeFunc(time); // working
        hasWorked = true;
        goingWaiting();
    }
    bool Timer::getHasWorked() { return hasWorked; }
    bool Timer::getIsWaiting() { return isWaiting; }

    void Timer::turnOff()
    {
        ligthRest.turnOff();
        ligthWait.turnOff();
        ligthWork.turnOff();
    }
    void Timer::goingWaiting()
    {
        turnOff();
        ligthWait.turnOn();
        isWaiting = true;
    };

    void Timer::change()
    {

        if (!isWaiting)
            reset();
        else if (hasWorked)
            goingResting(time_rest);
        else
            goingWorking(time_work);
    }
}