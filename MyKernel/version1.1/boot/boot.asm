BITS 16                  ; Operar em modo real de 16 bits
ORG 0x7c00               ; Endereço onde o BIOS carrega o bootloader

start:
    ; 1. Inicialização do stack
    cli                  ; Desabilita interrupções
    mov ax, 0x07c0       ; Segmento de memória atual
    mov ds, ax           ; Configura segmento de dados
    mov es, ax           ; Configura segmento extra
    mov ss, ax           ; Segmento de pilha
    mov sp, 0x7c00       ; Inicializa o stack pointer

    ; 2. Exibir mensagem na tela
    mov si, msg          ; Aponta para a string da mensagem
print_char:
    lodsb                ; Carrega próximo byte (caractere) de SI em AL
    cmp al, 0            ; Verifica se é o final da string
    je load_kernel       ; Se sim, pula para carregar kernel
    mov ah, 0x0e         ; Função BIOS para imprimir caractere
    int 0x10             ; Chamada de interrupção de vídeo
    jmp print_char       ; Continua imprimindo

load_kernel:
    ; 3. Carregar o kernel do disco para a memória (setor 2 para 0x1000)
    mov ah, 0x02         ; Função de leitura do setor
    mov al, 1            ; Número de setores a ler
    mov ch, 0            ; Cabeça 0
    mov cl, 2            ; Setor 2 (após o bootloader)
    mov dh, 0            ; Lado 0
    mov dl, 0x80         ; Primeiro disco rígido
    mov bx, 0x1000       ; Carregar kernel na memória em 0x1000
    int 0x13             ; Chamada de interrupção do disco

    ; 4. Transferência de controle para o kernel
    jmp 0x1000:0000      ; Saltar para o endereço do kernel

msg db "Iniciando RobOS, carregando kernel...", 0

times 510 - ($ - $$) db 0 ; Preenche o restante do setor com zeros
dw 0xaa55                ; Assinatura obrigatória do bootloader

