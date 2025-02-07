//Saída básica(VGA)
#define VGA_ADRESS 0xB8000
volatile char* vga_buffer = (volatile char*) VGA_ADRESS;

void print(const char* str){
    unsigned int i = 0;
    unsigned int j = 0;
    while (str[i] != '\0'){
        vga_buffer[j] = str[i];  //Caractere
        vga_buffer[j+1] = 0x07;  //Atributo(cor branca e fundo preto)
        i++;
        j +=2;
    }

}