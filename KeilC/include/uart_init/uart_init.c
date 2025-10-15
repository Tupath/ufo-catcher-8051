#include <REGX51.H>
#include "uart_init.h"


void uart_init(void) {
	TMOD = 0x20;       //timer1 che do 8bit tu dong nap lai
  TH1 = 0xFD;        //toc do baud 9600
  SCON = 0x50;       //8bit UART, 1 stopbit , cho phep nhan
  TR1 = 1;           //bat dau Timer1
}

void uart_sendchar(unsigned char c) {
	SBUF = c;          //gui ky tu
	while (!TI);       //doi gui xong
  TI = 0;            //xoa co truyen
}

//gui chuoi
void uart_sendstring(char *s) {
	while(*s) {
		uart_sendchar(*s++);
	}
}

//gui so dang thap phan (unsigned char)
void uart_sendnum(unsigned char num) {
	unsigned char hundreds, tens, ones;

	hundreds = num / 100;
	tens = (num / 10) % 10;
	ones = num % 10;

	if (hundreds > 0)
		uart_sendchar(hundreds + '0');
	if (hundreds > 0 || tens > 0)
		uart_sendchar(tens + '0');
	uart_sendchar(ones + '0');
}