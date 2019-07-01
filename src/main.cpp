#include "trafficlight.hpp"

int main() {
    event.rise(&timer_on);
    event.fall(&timer_off);
    green();
} 