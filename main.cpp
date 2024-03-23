#include "mbed.h"
// main() runs in its own thread in the OS
    DigitalOut led(LED1);
    DigitalIn button(BUTTON1);
int main(){


    enum State {state_on1, state_off1, state_on2, state_off2};
    State actual_state = state_on1;

    while (true) {

        switch(actual_state) {
        case state_on1:
                led = 1;
                ThisThread::sleep_for(2000ms);
                actual_state = state_off1;
            break;
        case state_off1:
                led = 0;
                ThisThread::sleep_for(500ms);
                actual_state = state_on2;
            break;
        case state_on2:
                led = 1;
                ThisThread::sleep_for(5000ms);
                actual_state = state_off2;
            break;
        case state_off2:
            led = 0;
            if(button == 0){
                actual_state = state_on1;
            }
            break;
        }
    }
}