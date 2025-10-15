#ifndef _uart_H
#define _uart_H

#include <REGX51.H>

    void uart_init(void);
    void uart_sendchar(unsigned char c);
    void uart_sendstring(char *s);
    void uart_sendnum(unsigned char num);

#endif