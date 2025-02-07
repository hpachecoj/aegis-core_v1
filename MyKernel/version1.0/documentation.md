# Escrevendo o próprio kernel
## Tecnologias, Frameworks e demais recursos
- Baseado no kernel da versão DeepSeek V3, um núcleo-teste está sendo escrito. Utilizo também na escrita do projeto a linguagem C e Assembly(obviamente).
## Componentes básicos de um Kernel

## Inicialização(Boot)
- Configura o ambiente de execução após o carregamento do bootloader.
### Bootloader
#### Inicialização do hardware
- Configuração do Ambiente: Deve inicializar o hardware básico, como a CPU, a memória e os dispositivos Input/Output
- Configuração da Pilha: Inicializar a pilha de execução, que é essencial para o funcionamento do código.
#### Detec