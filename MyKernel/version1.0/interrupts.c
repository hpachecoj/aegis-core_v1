// interrupts.c
#include <stdint.h>

// Estrutura do IDT (Interrupt Descriptor Table)
struct idt_entry {
    uint16_t base_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed));

struct idt_entry idt[256]; // 256 entradas possíveis

void idt_init() {
    // Configura a IDT
    // ... (preenche entradas para interrupções)
    asm volatile("lidt %0" : : "m" (idt)); // Carrega a IDT na CPU
}

// Handler genérico de interrupção
void irq_handler() {
    // Lógica para tratar interrupções (ex: timer, teclado)
}