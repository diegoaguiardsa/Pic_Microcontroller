/******************************************************************************                        
*                                                                             *
*   Projeto: Controle de Display LCD com Caracteres Personalizados            *
*   Autor: Diego Aguiar                                                       *
*                                                                             *
*   Este código é destinado a um microcontrolador PIC18F4520 que controla     *
*   um display LCD alfanumérico. Ele define caracteres personalizados         *
*   (cedilha, a com til, coração vazio e coração cheio) e os exibe no LCD.    *
*   Além disso, alterna entre a exibição do coração cheio e vazio em um       *
*   loop infinito.                                                            *
*                                                                             *
******************************************************************************/

#include <18f4520.h>         // Inclui o arquivo específico para o 
                             //microcontrolador PIC18F4520
#fuses HS, NOWDT             // Configura os fusíveis do microcontrolador 
                             // (cristal de alta velocidade e desativa o 
                             // watchdog timer)
#use delay(clock = 8000000)  // Define que a frequência do clock será em 8MHz

#define LCD_RS_PIN      PIN_D0  // Define o pino para RS (Register Select) 
                                // do LCD
#define LCD_RW_PIN      PIN_D1  // Define o pino para RW (Read/Write) do LCD
#define LCD_ENABLE_PIN  PIN_D2  // Define o pino para o pino de habilitação 
                                // (Enable) do LCD
#define LCD_DATA4       PIN_D4  // Define o pino para D4 (Data 4) do LCD
#define LCD_DATA5       PIN_D5  // Define o pino para D5 (Data 5) do LCD
#define LCD_DATA6       PIN_D6  // Define o pino para D6 (Data 6) do LCD
#define LCD_DATA7       PIN_D7  // Define o pino para D7 (Data 7) do LCD

#include <lcd.c>       // Inclui a biblioteca para controle do LCD

int cedilha[8] = {  // Define um caractere personalizado (cedilha)
    0b00000,
    0b01110,
    0b10000,
    0b10000,
    0b01110,
    0b00100,
    0b01000,
    0b00000
};

int a_til[8] = {  // Define um caractere personalizado (a com til)
    0b11111,
    0b00000,
    0b01110,
    0b00001,
    0b01111,
    0b10001,
    0b01111,
    0b00000
};

int coracao[8] = {  // Define um caractere personalizado (coração vazio)
    0b00000,
    0b01010,
    0b10101,
    0b10001,
    0b01010,
    0b00100,
    0b00000,
    0b00000
};

int coracao_cheio[8] = {  // Define um caractere personalizado (coração cheio)
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000,
    0b00000
};

void main (){
   lcd_init();  // Inicializa o LCD
   delay_ms(15);  // Aguarda 15 milissegundos

   lcd_set_cgram_char(0, cedilha); // Define o caractere personalizado 
                                   // na posição 0 da CGRAM
   lcd_set_cgram_char(1, a_til);   // Define o caractere personalizado 
                                   // na posição 1 da CGRAM
   lcd_set_cgram_char(2, coracao); // Define o caractere personalizado 
                                   // na posição 2 da CGRAM
   lcd_set_cgram_char(3, coracao_cheio); // Define o caractere personalizado 
                                         // na posição 3 da CGRAM

   lcd_gotoxy(1,1);  // Move o cursor para a posição (1,1)
   printf(lcd_putc,"Cora%c%co %c",0,1,2);  // Imprime o texto com os caracteres 
                                           // personalizados no LCD
   
   while(true){
      lcd_gotoxy(9,1);  // Move o cursor para a posição (9,1)
      printf(lcd_putc,"%c",3);// Imprime o caractere personalizado na posição 3
      delay_ms(500);  // Aguarda 500 milissegundos
      lcd_gotoxy(9,1);  // Move o cursor para a posição (9,1)
      printf(lcd_putc,"%c",2);// Imprime o caractere personalizado na posição 2
      delay_ms(500);  // Aguarda 500 milissegundos
   }
}
