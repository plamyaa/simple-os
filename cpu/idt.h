#ifndef IDT_H
#define IDT_H

#include "type.h"

/* Segment selector */
#define KERNEL_CS 0x08

typedef struct {
    int16_t low_offset;  // lowest 16 bits of hander function address
    int16_t sel;         // a code segment selector in GDT or LDT
    uint8_t  always0;     // unused, set to 0
    uint8_t  flags;       // gate type, dpl, and p fields
    int16_t high_offset; // highest 16 bits of handler function address
} __attribute__((packed)) idt_gate_t;

typedef struct {
    int16_t limit; // size of the IDT in bytes minus 1.
    uint32_t base;  // linear base address where the IDT starts.
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256

void set_idt_gate(int n, uint32_t handler);
void set_idt();

#endif