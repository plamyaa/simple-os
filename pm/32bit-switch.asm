[bits 16]
switch_to_pm:             ; protected mode
    cli                   ; disable interrupts
    lgdt [gdt_descriptor] ; load GDT
    mov eax, cr0          ; control register
    or eax, 0x1           ; set 32-bit mode in cr0
    mov cr0, eax          ; enabling PM
    jmp CODE_SEG:init_pm

[bits 32]
init_pm:
    mov ax, DATA_SEG ; update the segment register
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000 ; update the stack
    mov esp, ebp

    call BEGIN_PM
