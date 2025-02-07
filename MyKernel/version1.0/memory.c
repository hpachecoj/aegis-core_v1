//Gerenciamento de Memória
#define MEMORIZE_SIZE 0x100000 //1MB

uint32_t memory_map[MEMORY_SIZE / 4096]; // Bitmap para páginas de 4KB

void init_memory(){
    //Marca todas as páginas como livres (0) ou ocupadas (1)
    for (int i = 0; i <(MEMORIZE_SIZE / 4096); i++){
        memory_map[i] = 0;
    }
    // Reserva memória para o kernel
    // ...
}

void* alloc_page(){
    //Encontra uma página livre e aloca
    for(int i = 0; i < (MEMORIZE_SIZE / 4096); i++){
        if(memory_map[i] == 0){
            memory_map[i] = 1;
            return (void*)(i * 4096);
        }
    }
    return NULL; //Sem memóri livre
}