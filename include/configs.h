#ifndef CONFIGS
#define CONFIGS
#include <Arduino.h>
#include <LowPower.h>
#include "Pomodoro.h"


#define DEBUG false


#define BUTTON 2
#define SPEAKER 8
#define REST_PIN 4
#define WAIT_PIN 7
#define WORK_PIN 9
#define BEEP_DURATION 1500
#define BEEP_FEQUENCY 1000

#define _TIME_5_MIN 38U
#define _TIME_25_MIN 188u

#define _TIME_8_SEG 1U
#define _TIME_16_SEG 2U

namespace configs
{
    unsigned int rest_time = _TIME_5_MIN;
    unsigned int work_time = _TIME_25_MIN;

    void check_debug()
    {
        if (DEBUG)
        {
            rest_time = _TIME_8_SEG;
            work_time = _TIME_16_SEG;
        }
    }

    void timeFunc(unsigned int vezes)
    {
        for (unsigned int i = 0; i < vezes; i++)
        {
            LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_ON);
        }
    }
}

#endif