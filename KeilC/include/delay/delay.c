#include <REGX51.H>
#include "delay.h"

void delay(unsigned char ms){
	unsigned char x,y;
	for(x = 0; x < ms; x++)
		for(y = 0; y <125; y++);
}