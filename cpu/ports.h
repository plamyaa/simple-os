#ifndef PORTS_H
#define PORTS_H

#include <stdint.h>

uint8_t port_byte_in(int16_t port);
void port_byte_out(int16_t port, uint8_t data);
int16_t port_word_in(int16_t port);
void port_word_out(int16_t port, int16_t data);

#endif