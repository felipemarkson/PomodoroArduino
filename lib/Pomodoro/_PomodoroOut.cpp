#include <Arduino.h>
#include "_PomodoroOut.h"

namespace _PomodoroOut
{
    Out Out::create(int pin)
    {
        Out s;
        s.pin = pin;
        s.state = false;
        return s;
    }
    void Out::setState(bool setstate)
    {
        state = setstate;
        digitalWrite(pin, !state);
    }

    void Out::setUp()
    {
        pinMode(pin, OUTPUT);
        turnOff();
    }

    void Out::turnOn()
    {
        setState(true);
    }

    void Out::turnOff()
    {
        setState(false);
    }

    void Out::togleState()
    {
        state = !state;
        setState(state);
    }

    bool Out::getState()
    {
        return state;
    }
}