#include "timer.h"
#include "isr.h"
#include "ports.h"
#include "../libc/function.h"


uint32_t tick = 0;

static void
timer_callback(registers_t *r)
{
    tick++;
    UNUSED(r);
}

void
init_timer(uint32_t freq)
{
    uint32_t divisor;
    uint8_t low, high;

    register_interrupt_handler(IRQ0, timer_callback);

    divisor = 1193180 / freq;
    low = (uint8_t) (divisor & 0xFF);
    high = (uint8_t) ((divisor >> 8) & 0xFF);

    port_byte_out(0x43, 0x36);
    port_byte_out(0x40, low);
    port_byte_out(0x40, high);
}
