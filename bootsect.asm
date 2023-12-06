; A boot sector that boots a C kernel
[org 0x7c00]
KERNEL_OFFSET equ 0x1000 ; The same that we used when linking the kernel
    mov [BOOT_DRIVE], dl ; BIOS sets us the boot drive in 'dl' on boot

    mov bp, 0x9000       ; Set-up the stack
    mov sp, bp

    mov bx, MSG_REAL_MODE ; Announce that we are starting
    call print            ; Booting from 16-bit real mode
    call print_nl

    call load_kernel
    call switch_to_pm
    jmp $

%include "print/boot_sect_print.asm"
%include "print/boot_sect_print_hex.asm"
%include "disk/boot_sect_disk.asm"
%include "pm/32bit-gdt.asm"
%include "pm/32bit-print.asm"
%include "pm/32bit-switch.asm"

[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print
    call print_nl

    mov bx, KERNEL_OFFSET
    mov dh, 15              ; Load first 15 sectors to KERNEL_OFFSET
    mov dl, [BOOT_DRIVE]    ; Drive number
    call disk_load
    ret

[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call print_string_pm

    call KERNEL_OFFSET      ; Jump to the address of loaded kernel code

    jmp $

; Global variables
BOOT_DRIVE db 0
MSG_REAL_MODE db " Started in 16 - bit Real Mode " , 0
MSG_PROT_MODE db " Successfully landed in 32 - bit Protected Mode " , 0
MSG_LOAD_KERNEL db " Loading kernel into memory. " , 0

; Bootsector padding
times 510-($-$$) db 0
dw 0xaa55