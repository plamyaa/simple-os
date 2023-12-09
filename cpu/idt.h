#ifndef IDT_H
#define IDT_H

#include "type.h"

/* Segment selector */
#define KERNEL_CS 0x08

typedef struct {
    u16 low_offset;  // lowest 16 bits of hander function address
    u16 sel;         // a code segment selector in GDT or LDT
    u8  always0;     // unused, set to 0
    u8  flags;       // gate type, dpl, and p fields
    u16 high_offset; // highest 16 bits of handler function address
} __attribute__((packed)) idt_gate_t;

typedef struct {
    u16 limit; // size of the IDT in bytes minus 1.
    u32 base;  // linear base address where the IDT starts.
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256

void set_idt_gate(int n, u32 handler);
void set_idt();

#endif