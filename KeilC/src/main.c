#include <REGX51.H>

#include "uart_init.h"
#include "play_mode.h"
#include "delay.h"

sbit led1 = P1^0;
sbit led2 = P1^1;
sbit coinDetector = P1^3;

unsigned char x;
unsigned char y;
unsigned char z;



void main(void){
	
	uart_init();
	
	//khoi tao gia tri
	Init:
  x = 254/2;
  y = 254/2;
	z = 0;
	
	while(1){
		//chop tat led
		led1 = 1;
		led2 = 0;
		delay(2000);
		led1 = 0;
		led2 = 1;
		delay(2000);
		
		//kiem tra xu
		if(coinDetector == 0){
			delay(30);
			if(coinDetector == 0){
				led1 = 1;
				led2 = 1;
				play_mode(&x, &y, &z);
				
				//debug tren VIRTUAL TERMINAL
				uart_sendchar('X');
				uart_sendchar('=');
				uart_sendnum(x);
				uart_sendchar(' ');

				uart_sendchar('Y');
				uart_sendchar('=');
				uart_sendnum(y);
				uart_sendchar(' ');

				uart_sendchar('Z');
				uart_sendchar('=');
				uart_sendnum(z);
				uart_sendchar('\n'); // xuong dong
				uart_sendchar('\r');
				
				//khoi tao lai trang thai ban dau 
				goto Init;
			}
		}
	}
}