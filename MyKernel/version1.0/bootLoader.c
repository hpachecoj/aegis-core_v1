//Ponto de entrada do Kernel
// kernel.c
void kernel_main(){
    //Inicialização dos componentes críticos
    init_memory(); //Gerenciador de memória
    init_interrupts(); //Configura interrupções
    init_keyboard();//Driver de teclado
    //Loop infinito do kernel
    while(1){
        //Este loop mantém o sistema operacional ativo
    }
}

// Podemos inferir que aqui possui uma função principal que chama todas as demais 
// funções que de componentes críticos do sistema.

//Gerencia os principais recursos do computador como a memória, processador 
//e os dispositivos. O kernel é acionado quando o computador é ligado e 
//começa a detectar todo o hardware que ele(computador) possui.