/*
########
# The GROWbox Supervisor System (GROWSS)
# Nighthawk
# 4.20.20
#
# This project is released under The MIT License (MIT)
# Copyright 2020 Nighthawk
#
# Version: V20-04-20-V1B (Arduino Version):
        - beta version #1
        - works with bme280, moisture sensors, real time clock
        - has debug hooks, but not conforming to arduino debugging method yet
        - No Blynk implimentation yet

# Version: V20-07-01-V2B-V2B:
        - beta version #2
        - added Blynk mobile virtual pin reads (from arduino to mobile app)
        - renamed files and consolidated code to better work with Blynk
        - Code compiles but has not been tested with the Blynk mobile app yet
            - got to get local server configured for an additional device & design new Blynk mobile app
########

########
# classes & methods
########
*/
#pragma once

#ifndef _CONTROL_H_
#define _CONTROL_H_
#include <Arduino.h>
// exhaust fan control class & methods
class Exhaust_fan{
    public:
        float tempSetpoint; // temp set point when fan turns on. value changes depending on day or nite
        float dayTemp; // temp set point when lights are on
        float niteTemp; // temp set point when lights are off
        float tempHysteresis; // temp range the fan turns on and off
        float humidSetpoint; // humidity set point when fan turns on
        float humidHysteresis; // humid range the fan turns on and off
        bool exFanIsOn; // flag indicates when exhaust fan is on

        // methods
        bool exhaust_fan_cntrl(float, float, float, float, float, float);

};

/****************************************************************/
// grow light class & methods
class Light
{   public:
        int lightOnHour; // hour when the lights are turned on
        int lightOnMinute;  // min when the lights are turned on
        int lightOffHour; // hour when the lights are turned off
        int lightOffMinute; // minute when the lights are turned off
        bool lightIsOn; // flag indicates when light is on
        
        // methods
        bool light_cntrl(int, int, int);
};

/****************************************************************/
// humidifier control classes & methods
class Humid_Cntrl {
    public:
        float humiditySetpoint;
        float humidityHysteresis;
        bool humidifierIsOn;
    
    // methods
        bool humid_cntrl(float, float, float);

};
#endif