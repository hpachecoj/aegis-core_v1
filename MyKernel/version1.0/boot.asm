; boot.asm
section .text
global _start
_start:
    mov ax, 0x07C0
    mov ds, ax
    cli        ;desabilita interrupções
    ;Configura stack
    mov ax, 0x9000
    mov ss, ax
    mov sp, 0xFFFF
    sti        ; Habilita interrupções
    ; Carrega o kernel para a memória
    ; ...(leia setores do disco)
    jmp 0x8000:0x0 ; Salta o para o kernel em modo protegiso(se aplicável)