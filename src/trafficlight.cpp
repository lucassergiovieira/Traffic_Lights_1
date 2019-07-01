#include "trafficlight.hpp"
DigitalOut leds[]={(PD_12),(PD_13),(PD_14)};
int i=0;
Timeout timeout;
InterruptIn event(PA_0);
int t;
Timer timer;
Ticker ticker;


void off_leds(){
    for(i=0;i<=2;i++){
            leds[i]=0;
        }
}

void semaforo(){
    }
    void green(){
    off_leds();
    timeout.attach(&yellow, 20);
    leds[0] = 1; //LED verde acende
    event.rise(&blink_alert);
}
void yellow(){
    off_leds();
    timeout.attach(&red, 4);
    leds[1] = 1; //LED amarelo acende
}
void red(){
    off_leds();
    timeout.attach(&green, 10);
    leds[2] = 1; //LED vermelho acende
    }
    
void blink_alert(){
    leds[1]= !leds[1];
}

void timer_on(){
    timer.start();
}

void timer_off(){
    timer.stop();
    t = timer.read();
    if(t<=3&&LED[0]==1){
        green();
        }
     else if(t>3&&t<=10){
        off_leds();
        timeout.detach();
        ticker.attach(&blink_alert,0.5);
        }
     else if(t>10){
        ticker.detach();
        timeout.detach();
        off_leds();
        }
    timer.reset();
}
© 2019 GitHub, Inc.