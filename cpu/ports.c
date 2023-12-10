#include "ports.h"

uint8_t
port_byte_in(int16_t port)
{
    uint8_t result;
    asm("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void
port_byte_out(int16_t port, uint8_t data)
{
    asm("out %%al, %%dx" : : "a" (data), "d" (port));
}

int16_t
port_word_in(int16_t port)
{
    int16_t result;
    asm("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

void
port_word_out(int16_t port, int16_t data)
{
    asm("out %%ax, %%dx" : : "a" (data), "d" (port));
}