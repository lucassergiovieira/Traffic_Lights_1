#ifndef TRAFFICLIGHT_HPP
#define TRAFFICLIGHT_HPP
#include "mbed.h"

extern DigitalOut LED[];
extern InterruptIn event;
void off_leds();
void green();
void yellow();
void red();
void blink_alert();
void timer_on();
void timer_off();
void semaforo();

#endif