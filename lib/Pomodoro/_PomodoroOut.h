#ifndef SAIDA_H
#define SAIDA_H

namespace _PomodoroOut
{
    struct Out
    {
    public:
        void setUp();
        void setState(bool setstate);
        void turnOn();
        void turnOff();
        void togleState();
        bool getState();
        static Out create(int pin);
    private:
        int pin;
        bool state;        
    };
   
}

#endif