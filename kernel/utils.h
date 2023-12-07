#ifndef UTILS_H
#define UTILS_H

#include "../cpu/types.h"

void memory_copy(char *source, char *dest, int nbytes);
void int_to_ascii(int i, char str[]);
void memory_set(u8 *dest, u8 val, u32 len);
void reverse(char s[]);
int strlen(char s[]);

#endif