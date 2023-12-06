gdt_start:
    dd 0x0       ; null descriptor
    dd 0x0

gdt_code:        ; The code segment descriptor
    dw 0xffff    ; Limit
    dw 0x0       ; Base
    db 0x0       ; Base
    db 10011010b ; 1st flags
    db 11001111b ; 2nd flags
    db 0x0       ; Base

gdt_data:        ; The data segment descriptor
    dw 0xffff    ; Limit
    dw 0x0       ; Base
    db 0x0       ; Base
    db 10010010b ; 1st flags
    db 11001111b ; 2nd flags
    db 0x0       ; Base

gdt_end:         ; This is label marking the end of the GDT

gdt_descriptor:
    dw gdt_end - gdt_start - 1 ; Limit field of the GDT descriptor
    dd gdt_start               ; Base address of GDT

CODE_SEG equ gdt_code - gdt_start ; Calculates the offset of the gdt_code
DATA_SEG equ gdt_data - gdt_start
