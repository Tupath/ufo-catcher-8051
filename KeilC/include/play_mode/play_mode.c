#include <REGX51.H>
#include "uart_init.h"
#include "delay.h"
#include "play_mode.h"

void play_mode(unsigned char *x, unsigned char *y, unsigned char *z) {
    bit coinEnable = 1;
    unsigned char buttonState = 0;
    
    while (coinEnable) {
        buttonState = P2 | 0xE0; 
        /*0xE0 = 1110 0000
          khi OR voi 0xE0 thi P2.5–P2.7 luon = 1
          chi doc cac bit thap P2.0–P2.4 de kiem tra nut nhan
        */

        switch (buttonState) {
            case 0xFE: //up (P2.0 = 0)
                if ((*y) <= 253) (*y) += 1;
								delay(10);
                break;

            case 0xFD: //down(P2.1 = 0)
                if ((*y) >= 2) (*y) -= 1;
								delay(10);
                break;

            case 0xFB: //left (P2.2 = 0)
                if ((*x) >= 2) (*x) -= 1;
								delay(10);
                break;

            case 0xF7: //right (P2.3 = 0)
                if ((*x) <= 253) (*x) += 1;
								delay(10);
                break;

            default:
                break;
        } 

        //drop (P2.4 = 0)
        if (buttonState == 0xEF) {
            delay(30);
            buttonState = P2 | 0xE0;

            if (buttonState == 0xEF) {
                unsigned char i;
                for (i = 0; i < 254; i++) {
                    if ((*z) <= 245) (*z) += 1;
                    delay(10);
                }
								coinEnable = 0; //thoat khoi vong lap, ham ket thuc
            }
        }
    }
}

